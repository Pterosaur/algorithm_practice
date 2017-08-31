// 664. Strange Printer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//664. Strange Printer
//There is a strange printer with the following two special requirements:
//
//The printer can only print a sequence of the same character each time.
//At each turn, the printer can print new characters starting from and ending at any places, and will cover the original existing characters.
//Given a string consists of lower English letters only, your job is to count the minimum number of turns the printer needed in order to print it.
//
//Example 1:
//Input: "aaabbb"
//Output: 2
//Explanation: Print "aaa" first and then print "bbb".
//Example 2:
//Input: "aba"
//Output: 2
//Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
//Hint: Length of the given string will not exceed 100.

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) {
            return 0;
        }
        vector< vector<int> > record(s.length() + 1, vector<int>(s.length(), 0));

        for (int i = 0; i < s.length(); i++) {
            record[i][i] = 1;
        }

        for (int i = 1; i < s.length(); i++) {

            for (int j = i - 1; j >= 0; j--) {
                int min_step = numeric_limits<int>::max();
                for (int k = j; k < i; k++) {
                     min_step = min(min_step,(s[k] == s[i]) ? (record[j][k] + record[k+1][i-1]) : (record[j][i-1] + 1));
                }
                record[j][i] = min_step;
            }

        }
        return record[0][s.length() - 1];
    }
};


int main()
{
    Solution s;
    s.strangePrinter("aba");
    return 0;
}

