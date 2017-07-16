// 10. Regular Expression Matching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//Implement regular expression matching with support for '.' and '*'.
//
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
//
//The matching should cover the entire input string(not partial).
//
//The function prototype should be :
//bool isMatch(const char *s, const char *p)
//
//Some examples :
//isMatch("aa", "a") ¡ú false
//isMatch("aa", "aa") ¡ú true
//isMatch("aaa", "aa") ¡ú false
//isMatch("aa", "a*") ¡ú true
//isMatch("aa", ".*") ¡ú true
//isMatch("ab", ".*") ¡ú true
//isMatch("aab", "c*a*b") ¡ú true

#include <string>
#include <vector>
using namespace std;

struct edge;
struct node {
    vector<edge *> m_next;
    bool jump(char p) {

    }
};
struct edge {
};


class Solution {
public:


    bool isMatch(string s, string p) {
        std::vector<std::vector<bool> > match_map(p.length(), std::vector<bool>(s.length(), false));

        int start = 0, end = 1;
        for (int i = 0; i < p.length(); i++) {
            for (int j = 0; j < s.length(); j ++) {
                if (p[i] == '.') {
                    match_map[i][j] = (i == 0 && j == 0) ? true : match_map[i - 1][j-1];
                }
                else if (p[i] == '*') {

                }
                else {

                }
            }
        }
    }
};


int main()
{
    Solution s;
    string s1 = "aa", s2 = "c*.*";
    bool result =  s.isMatch(s1, s2);
    return 0;
}

