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
//
//struct edge;
//struct node {
//    vector<edge *> m_next;
//    bool jump(char p) {
//
//    }
//};
//struct edge {
//};
//
//
//class Solution {
//public:
//
//
//    bool isMatch(string s, string p) {
//        std::vector<std::vector<bool> > match_map(p.length(), std::vector<bool>(s.length(), false));
//
//        int start = 0, end = 1;
//        for (int i = 0; i < p.length(); i++) {
//            for (int j = 0; j < s.length(); j ++) {
//                if (p[i] == '.') {
//                    match_map[i][j] = (i == 0 && j == 0) ? true : match_map[i - 1][j-1];
//                }
//                else if (p[i] == '*') {
//
//                }
//                else {
//
//                }
//            }
//        }
//    }
//};


class Solution {
public:
    bool check_valid(const string & p) {
        if (p.empty()) {
            return true;
        }
        if (p[0] == '*') {
            return false;
        }
        for (int i = 1; i < p.length(); i++) {
            if (p[i] == '*' && p[i - 1] == '*') {
                return false;
            }
        }
        return true;
    }
    bool isMatch(string s, string p) {
        if (!check_valid(p)) {
            return false;
        }
        vector<vector<bool> > record(p.size() + 1, vector<bool>(s.length() + 1, false));
        record[0][0] = true;
        for (int i = 1; i <= p.length(); i++) {
            for (int j = 0; j <= s.length(); j++) {
                switch (p[i - 1]) {
                case '.':
                    record[i][j] = j > 0 && record[i - 1][j - 1];
                    break;
                case '*':
                    record[i][j] = 
                        (i == 2 && j == 0) || 
                        record[i - 2][j] ||
                        (j > 0 && p[i-2] == '.' &&  (record[i - 1][j - 1] || record[i][j-1])) || 
                        (j > 0 && (record[i-2][j-1] || record[i][j-1]) && s[j-1]==p[i-2]);
                    break;
                default:
                    record[i][j] = j > 0 && record[i - 1][j - 1] && p[i - 1] == s[j - 1];
                    break;
                }
            }
        }
        return record[p.length()][s.length()];
    }
};

int main()
{
    Solution s;
    string s1 = "aaa", s2 = ".*";
    bool result =  s.isMatch(s1, s2);
    return 0;
}

