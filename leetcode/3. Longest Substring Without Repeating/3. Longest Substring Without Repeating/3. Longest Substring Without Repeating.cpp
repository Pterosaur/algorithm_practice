// 3. Longest Substring Without Repeating.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//3. Longest Substring Without Repeating Characters
//
//Given a string, find the length of the longest substring without repeating characters.
//
//Examples:
//
//Given "abcabcbb", the answer is "abc", which the length is 3.
//
//Given "bbbbb", the answer is "b", with the length of 1.
//
//Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int candidate[255];
        char last = '0';
        int longest = 0;
        int previous_longest = 0;
        int index = 0;
        fill(candidate, candidate + 255, -1);

        for (char c : s) {
            if (candidate[c] == -1) {
                previous_longest++;
            }
            else {
                previous_longest = min(previous_longest + 1, index - candidate[c]);
            }
            candidate[c] = index;
            longest = max(longest, previous_longest);
            index++;
        }
        return  longest;
    }
};


int main()
{
    Solution s1;
    s1.lengthOfLongestSubstring("abcabcbb");
    return 0;
}

