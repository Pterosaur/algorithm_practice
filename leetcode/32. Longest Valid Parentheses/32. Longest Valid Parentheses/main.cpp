//32. Longest Valid Parentheses
//
//Given a string containing just the characters '(' and ')', find the length of the longest valid(well - formed) parentheses substring.
//
//For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
//Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
//
//Subscribe to see which companies asked this question.
//

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {

public:
	int longestValidParentheses(string s) {
		if (s.empty())
			return 0;
		vector<int > record(s.length());
		record[0] = 0;
		int longest = 0;
		for (int i = 1; i < s.length(); i++) {
			if (s[i] == '(') {
				record[i] = 0;
			}
			else if (s[i] == ')') {
				if (s[i - 1] == '(') {
					record[i] = (i >= 2 ? record[i - 2] : 0) + 2;
				}
				else {
					if (record[i - 1] >= i ) {
						record[i] = 0;
					}
					else if(s[i - 1- record[i - 1]] == '(') {
						record[i] = record[i - 1] + 2 + (i - 2 > record[i - 1] ? record[i - 2 - record[i - 1]] : 0);
					}
					else {
						record[i] = 0;
					}
				}
			}
			longest = max(longest, record[i]);
		}
		return longest;
	}
};


int main() {
	Solution s;
	int c = s.longestValidParentheses("(()())");
	return 0;
}