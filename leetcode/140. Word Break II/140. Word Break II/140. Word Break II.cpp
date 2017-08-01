// 140. Word Break II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//140. Word Break II
//Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.
//
//Return all such possible sentences.
//
//For example, given
//s = "catsanddog",
//dict = ["cat", "cats", "and", "sand", "dog"].
//
//A solution is ["cats and dog", "cat sand dog"].

#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    void generate(
        std::vector<std::vector<int> > & record,
        int len,
        std::vector<string> & wordDict,
        std::vector<string> & result,
        std::string buffer
        ) {
        if (len == record.size()) {
            result.push_back(buffer);
            return;
        }
        for (auto & index : record[len]) {
            generate(record, len + wordDict[index].length(), wordDict, result, (!buffer.empty()) ? (buffer + " " + wordDict[index]) : wordDict[index]);
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        std::vector<std::vector<int> > m_record(s.length());
        for (auto & vet : m_record) {
            vet.reserve(wordDict.size());
        }
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = 0; j < wordDict.size(); j++) {
                int end = (i + wordDict[j].length());
                if ( end > s.length()) {
                    continue;
                }
                else if (end == s.length()) {
                    if (0 == strncmp(wordDict[j].c_str(), &s[i], wordDict[j].length())) {
                        m_record[i].push_back(j);
                    }
                }
                else {
                    if (!m_record[i + wordDict[j].length()].empty()) {
                        if (0 == strncmp(wordDict[j].c_str(), &s[i], wordDict[j].length())) {
                            m_record[i].push_back(j);
                        }
                    }
                }
            }
        }

        std::vector<std::string> result;
        generate(m_record, 0, wordDict, result, "");
        return result;
    }
};


int main()
{
    Solution s;
    vector<string> dict = {"cat","cats", "and","sand","dog"};
    s.wordBreak("catsanddog", dict);
    return 0;
}

