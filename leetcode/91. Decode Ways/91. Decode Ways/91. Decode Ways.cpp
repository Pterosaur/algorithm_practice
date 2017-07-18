// 91. Decode Ways.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//91. Decode Ways
//A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//Given an encoded message containing digits, determine the total number of ways to decode it.
//
//For example,
//Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//
//The number of ways decoding "12" is 2.

#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        int combine_count = 0;
        int single_count = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != '0') {
                single_count = single_count + combine_count;
                if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                    combine_count = single_count - combine_count;
                }
                else {
                    combine_count = 0;
                }
            }
            else {
                if (s[i - 1] == '0' || s[i - 1] > '2') {
                    return 0;
                }
                combine_count = single_count;
                single_count = 0;
            }
        }
        return combine_count + single_count;
    }
};


int main()
{
    Solution s1;
    int result = s1.numDecodings("101");
    return 0;
}

