// 151. Reverse Words in a String.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//151. Reverse Words in a String
//Given an input string, reverse the string word by word.
//
//For example,
//Given s = "the sky is blue",
//return "blue is sky the".
//
//Update (2015-02-12):
//For C programmers: Try to solve it in-place in O(1) space.

#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    void trim(string & s) {
        auto bitr = s.begin();
        auto eitr = s.begin();
        while (*eitr == ' ') {
            eitr++;
        }
        while(eitr < s.end()) {
            *bitr = *eitr;
            bitr++;
            eitr++;
        }
        s.erase(bitr, s.end());
    }
    void compress_spaces(string & s) {
        auto bitr = s.begin();
        auto eitr = s.begin();
        bool first_space = false;
        while (eitr < s.end()) {
            if (*eitr != ' ') {
                first_space = true;
                *bitr = *eitr;
                bitr++;
            }
            else {
                if (first_space) {
                    first_space = false;
                    *bitr = *eitr;
                    bitr++;
                }
            }

            eitr++;
        }
        s.erase(bitr, s.end());
    }
    void reverseWords(string &s) {
        compress_spaces(s);
        std::reverse(s.begin(), s.end());
        trim(s);
        auto bitr = s.begin();
        auto eitr = s.begin();
        for (; eitr < s.end(); eitr++) {
            if (*eitr == ' ') {
                std:reverse(bitr, eitr);
                bitr = eitr + 1;
            }
        }
        std::reverse(bitr, eitr);
    }
};


int main()
{
    Solution s;
    string str = "  1 ";
    s.reverseWords(str);
    return 0;
}

