// 516. Longest Palindromic Subsequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//516. Longest Palindromic Subsequence
//Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
//
//Example 1:
//Input:
//
//"bbbab"
//Output:
//4
//One possible longest palindromic subsequence is "bbbb".
//Example 2:
//Input:
//
//"cbbd"
//Output:
//2
//One possible longest palindromic subsequence is "bb".


#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty()) {
            return 0;
        }
        //string rs = s;
        //reverse(rs.begin(), rs.end());
        vector<int> record[2];
        record[0].resize(s.length() + 1, 0);
        record[1].resize(s.length() + 1, 0);

        vector<int> * cur = &record[0];
        vector<int> * pre = &record[1];


        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == s[i]) {
                    (*cur)[j + 1] = (*pre)[j] + 1;
                }
                else {
                    (*cur)[j + 1] = max((*pre)[j + 1], (*cur)[j]);
                }
            }
            swap(cur, pre);
        }

        return pre->back();

    }
};



int main()
{
    Solution s1;
    int l = s1.longestPalindromeSubseq("abba");
    return 0;
}

