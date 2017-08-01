// 139. Word Break.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//139. Word Break
//Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.
//
//For example, given
//s = "leetcode",
//dict = ["leet", "code"].
//
//Return true because "leetcode" can be segmented as "leet code".
//
//UPDATE (2017/1/4):
//The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.

#include <vector>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::vector<bool> m_record(s.length(), false);
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = 0; j < wordDict.size(); j++) {
                int end = (i + wordDict[j].length());
                if ( end > s.length()) {
                    continue;
                }
                else if (end == s.length()) {
                    m_record[i] = (0 == strncmp(wordDict[j].c_str(), &s[i], wordDict[j].length()));
                }
                else {
                    if (m_record[i + wordDict[j].length()]) {
                        m_record[i] = (0 == strncmp(wordDict[j].c_str(), &s[i], wordDict[j].length()));
                    }
                }
                if (m_record[i]) {
                    break;
                }
            }
        }
        return m_record[0];
    }
};

int main()
{
    Solution s;
    vector<string> dict = {"leet","code"};
    s.wordBreak("leetcode", dict);
    return 0;
}

