// 131. Palindrome Partitioning.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//131. Palindrome Partitioning
//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return all possible palindrome partitioning of s.
//
//For example, given s = "aab",
//Return
//
//[
//  ["aa","b"],
//  ["a","a","b"]
//]

#include <vector>
#include <stack>
#include <string>

using namespace std;


class Solution {
private:
    void generate(
        vector<vector<int> > & indexs,
        vector<vector<string> > & result,
        string & s,
        int left,
        vector<string> & before) {
        for (auto right : indexs[left]) {
            before.push_back(string(s.begin() + left, s.begin() + right + 1));
            if (right == s.length() - 1) {
                result.push_back(before);
            }
            else {
                generate(indexs, result, s, right + 1, before);
            }
            before.pop_back();
        }
    }
public:

    vector<vector<string>> partition(string s) {
        if (s.empty()) {
            return vector<vector<string> >();
        }
        vector<vector<int> > record(s.length());
        for (auto & vet : record) {
            vet.reserve(s.length());
        }
        record.back().push_back(s.length() - 1);
        for (int i = s.length() - 2; i >= 0; i--) {
            record[i].push_back(i);
            if ( s[i] == s[i + 1]) {
                record[i].push_back(i + 1);
            }
            for (int left : record[i + 1]) {
                if (left == s.length() - 1) {
                    continue;
                }
                if (s[i] == s[left + 1]) {
                    record[i].push_back(left + 1);
                }
            }
        }
        vector<vector<string> > result;
        vector<string> tmp;
        tmp.reserve(s.length());
        generate(record, result, s, 0, tmp);
        return result;
    }
};

int main()
{
    Solution s1;
    string input = "aab";
    auto output = s1.partition(input);
    return 0;
}

