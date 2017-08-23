// 464. Can I Win.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//464. Can I Win
//In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.
//
//What if we change the game so that players cannot re-use integers?
//
//For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.
//
//Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.
//
//You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.
//
//Example
//
//Input:
//maxChoosableInteger = 10
//desiredTotal = 11
//
//Output:
//false
//
//Explanation:
//No matter which integer the first player choose, the first player will lose.
//The first player can choose an integer from 1 up to 10.
//If the first player choose 1, the second player can only choose integers from 2 up to 10.
//The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
//Same with other integers chosen by the first player, the second player will always win.

#include <vector>
#include <algorithm>
#include <cstdint>
#include <unordered_map>

using namespace std;

class candidate_set {
private:
    vector<bool> m_buffer;
public:
    candidate_set(size_t total) {
        m_buffer.resize(total + 1, true);
    }
    bool get(size_t index) const {
        return m_buffer[index];
    }
    void set(size_t index, bool value) {
        if (index < m_buffer.size()) {
            m_buffer[index] = value;
        }
    }
    size_t size() const {
        return m_buffer.size();
    }

    bool operator == (const candidate_set & cs) const{
        return m_buffer == cs.m_buffer;
    }
    size_t hash() const {
        return std::hash<vector<bool>>()(m_buffer);
    }
};

struct candidate_set_hash {
    size_t operator()(const candidate_set & cs) const {
        return cs.hash();
    }
};


class Solution {
private:
    unordered_map<candidate_set, bool, candidate_set_hash> m_record;
    enum Round {
        My,
        Opponent,
    };

    bool canIWin(candidate_set & choosable_set, int desiredTotal, Round rd) {
        auto pre_result = m_record.find(choosable_set);
        if (pre_result != m_record.end()) {
            return pre_result->second;
        }
        bool result = false;
        if (rd == My) {
            for (int i = 1; i < choosable_set.size(); i++) {
                if (choosable_set.get(i)) {
                    choosable_set.set(i, false);
                    if ((desiredTotal - i) <= 0 || canIWin(choosable_set, desiredTotal - i, Opponent)) {
                        choosable_set.set(i, true);
                        result = true;
                        goto OUTPUT;
                    }
                    choosable_set.set(i, true);
                }
            }
            result = false;
        }
        else {
            for (int i = 1; i < choosable_set.size(); i++) {
                if (choosable_set.get(i)) {
                    choosable_set.set(i, false);
                    if ((desiredTotal - i) <= 0 || !canIWin(choosable_set, desiredTotal - i, My)) {
                        choosable_set.set(i, true);
                        result = false;
                        goto OUTPUT;
                    }
                    choosable_set.set(i, true);
                }
            }
            result = true;
        }

OUTPUT:
        m_record[choosable_set] = result;
        return result;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) {
            return true;
        }
        else if (((1 + maxChoosableInteger)*maxChoosableInteger) / 2 < desiredTotal) {
            return false;
        }
        candidate_set choosable_set(maxChoosableInteger);
        return canIWin(choosable_set, desiredTotal, My);

    }
};




class Solution_int {
private:
    unordered_map<size_t, bool> m_record;
    int m_total;
    enum Round {
        My,
        Opponent,
    };

    bool canIWin(size_t choosable_set, int desiredTotal, Round rd) {
        auto pre_result = m_record.find(choosable_set);
        if (pre_result != m_record.end()) {
            return pre_result->second;
        }
        bool result = false;
        if (rd == My) {
            for (int i = 1; i <= m_total; i++) {
                if (choosable_set & ((size_t)1<<i)) {
                    size_t next_choosable = choosable_set;
                    next_choosable &= ~((size_t)1 << i);
                    if ((desiredTotal - i) <= 0 || canIWin(next_choosable, desiredTotal - i, Opponent)) {
                        result = true;
                        goto OUTPUT;
                    }
                }
            }
            result = false;
        }
        else {
            for (int i = 1; i <= m_total; i++) {
                if (choosable_set & ((size_t)1<<i)) {
                    size_t next_choosable = choosable_set;
                    next_choosable &= ~((size_t)1 << i);
                    if ((desiredTotal - i) <= 0 || !canIWin(next_choosable, desiredTotal - i, My)) {
                        result = false;
                        goto OUTPUT;
                    }
                }
            }
            result = true;
        }

OUTPUT:
        m_record[choosable_set] = result;
        return result;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) {
            return true;
        }
        else if (((1 + maxChoosableInteger)*maxChoosableInteger) / 2 < desiredTotal) {
            return false;
        }
        m_total = maxChoosableInteger;
        size_t choosable_set = 0;
        for (int i = 1; i <= m_total; i++) {
            choosable_set |= ((size_t)1 << i);
        }
        return canIWin(choosable_set, desiredTotal, My);

    }
};




#include <iostream>
int main()
{
    Solution_int s;
    //std::cout <<  s.canIWin(20, 200) << std::endl;
    bool result = s.canIWin(10, 11);
    return 0;
}



