// 44. Wildcard Matching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//
//44. Wildcard Matching
//Implement wildcard pattern matching with support for '?' and '*'.
//
//'?' Matches any single character.
//'*' Matches any sequence of characters (including the empty sequence).
//
//The matching should cover the entire input string (not partial).
//
//The function prototype should be:
//bool isMatch(const char *s, const char *p)
//
//Some examples:
//isMatch("aa","a") ? false
//isMatch("aa","aa") ? true
//isMatch("aaa","aa") ? false
//isMatch("aa", "*") ? true
//isMatch("aa", "a*") ? true
//isMatch("ab", "?*") ? true
//isMatch("aab", "c*a*b") ? false

#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<bool> > m_record;
public:
    bool check_valid(const string & p) {
        if (p.empty()) {
            return true;
        }
        if (p.front() == '*') {
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
        if (p.empty() && !s.empty()) {
            return false;
        }
        //if ( ! check_valid(p)) {
            //return false;
        //}

        m_record.resize(p.size() + 1, vector<bool>(s.size() + 1));
        m_record[0][0] = true;
        if (!p.empty() && p[0] == '*') {
            for (int i = 0; i <= s.length(); i++) {
                m_record[1][i] = true;
            }
        }
        for (int i = 1; i <= p.length(); i++) {
            for (int j = 0; j <= s.length(); j++) {
                switch (p[i - 1]) {
                case '*':
                    m_record[i][j] = m_record[i - 1][j] || (j > 0 && (m_record[i - 1][j - 1] || m_record[i][j-1]));
                    break;
                case '?':
                    m_record[i][j] = j > 0 && m_record[i - 1][j - 1];
                    break;
                default:
                    m_record[i][j] = j > 0 && (m_record[i - 1][j - 1] && (p[i - 1] == s[j - 1]));
                    break;
                }
            }
        }

        return m_record[p.length()][s.length()];
    }
};

int main()
{

    Solution s1;
    s1.isMatch("aab", "c*a*b");
    return 0;
}

