// 132. Palindrome Partitioning II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//
//132. Palindrome Partitioning II
//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return the minimum cuts needed for a palindrome partitioning of s.
//
//For example, given s = "aab",
//Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
using namespace std;

class Solution {

public:
    
    int minCut(string s) {
        if (s.length() <= 1) {
            return 0;
        }
        vector<int> min_cut(s.length(), numeric_limits<int>::max());
        vector<int> left_bounds[2];
        vector<int> * last = &left_bounds[0];
        vector<int> * cur = &left_bounds[1];
        last->reserve(s.length());
        cur->reserve(s.length());
        min_cut[0] = 0;
        last->push_back(1);
        if (s[0] == s[1]) {
            last->push_back(0);
            min_cut[1] = 0;
        }
        else {
            min_cut[1] = 1;
        }
        for (int i = 2; i < s.length(); i++) {
            min_cut[i] = 1 + min_cut[i - 1];
            cur->push_back(i);
            if (s[i] == s[i - 1]) {
                min_cut[i] = min(min_cut[i - 2] + 1, min_cut[i]);
                cur->push_back(i - 1);
            }
            for (auto & left : *last) {
                if (left == 0) {
                    continue;
                }
                if (s[i] == s[left - 1]) {
                    if ((left - 1) == 0) {
                        min_cut[i] = 0;
                    }
                    else {
                        min_cut[i] = min(min_cut[i], (min_cut[left - 2] + 1));
                    }
                    cur->push_back(left - 1);
                }
            }
            swap(cur, last);
            cur->clear();
        }
        return min_cut.back();
    }
};


int main()
{
    Solution s;
    string input = "efe";
    auto output = s.minCut(input);
    return 0;
}

