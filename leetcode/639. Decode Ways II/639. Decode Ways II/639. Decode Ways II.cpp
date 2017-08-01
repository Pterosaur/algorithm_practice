// 639. Decode Ways II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//639. Decode Ways II
//A message containing letters from A-Z is being encoded to numbers using the following mapping way:
//
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.
//
//Given the encoded message containing digits and the character '*', return the total number of ways to decode it.
//
//Also, since the answer may be very large, you should return the output mod 109 + 7.
//
//Example 1:
//Input: "*"
//Output: 9
//Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
//Example 2:
//Input: "1*"
//Output: 9 + 9 = 18

#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        std::uint64_t single_count = 1;
        std::uint64_t combine_count = 0;
        std::uint64_t last_star_count = 1;
        if (s[0] == '*') {
            single_count = 9;
        }
        else if (s[0] == '0') {
            return 0;
        }


        for (int i = 1; i < s.length(); i++) {
            
            //if (single_count >= (std::uint64_t)(1e9 + 7)) {
            //    single_count -= (std::uint64_t)(1e9 + 7);
            //}
            //if (combine_count >= (std::uint64_t)(1e9 + 7)) {
            //    combine_count -= (std::uint64_t)(1e9 + 7);
            //}
            //single_count = single_count % (std::uint64_t(1e9) + 7);
            //combine_count = combine_count % (std::uint64_t(1e9) + 7);
            std::uint64_t cur_single_count = single_count;
            std::uint64_t cur_combine_count = combine_count;

            if ((s[i - 1] != '*' && s[i - 1] != '1' && s[i-1] != '2') && s[i] == '0') {
                return 0;
            }


            //...1? ...2?
            if ((s[i - 1] == '1' && s[i] >= '1' && s[i] <= '9')
                ||
                (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                single_count = (cur_single_count+ cur_combine_count);
                combine_count = cur_single_count;
            }

            //...10 ...20
            else if ((s[i - 1] == '1' || s[i - 1] == '2') && s[i] == '0') {
                combine_count = cur_single_count;
                single_count = 0;
            }

            

            //...1*
            else if (s[i - 1] == '1' && s[i] == '*') {
                single_count = (cur_combine_count + cur_single_count) * 9;
                combine_count = (cur_single_count) * 9;
                last_star_count = cur_single_count;
            }
            
            //...2*
            else if (s[i - 1] == '2' && s[i] == '*') {
                single_count = (cur_combine_count + cur_single_count) * 9;
                combine_count = (cur_single_count) * 6;
                last_star_count = cur_single_count;
            }

            //...**
            else if (s[i - 1] == '*' && s[i] == '*') {
                single_count = (cur_combine_count + cur_single_count) * 9;
                combine_count = last_star_count * 9 + last_star_count * 6;
                last_star_count = (cur_combine_count + cur_single_count);
            }
            
            //...[^12*]*
            else if (s[i] == '*') {
                single_count = (cur_combine_count + cur_single_count) * 9;
                combine_count = 0;
            }

            //...*0
            else if (s[i - 1] == '*' && s[i] == '0') {
                single_count = 0;
                combine_count = last_star_count* 2;
            }

            //...*[1-6]
            else if (s[i - 1] == '*' && s[i] <= '6' && s[i] >= '1') {
                single_count = cur_single_count + cur_combine_count;
                combine_count = last_star_count * 2;
            }

            //...*[7-9]
            else if (s[i - 1] == '*' && s[i] >= '7' && s[i] <= '9') {
                single_count = cur_single_count + cur_combine_count;
                combine_count = last_star_count;
            }

            else {
                single_count = cur_single_count + cur_combine_count;
                combine_count = 0;
            }
        }

        return (single_count + combine_count) % ((std::uint64_t)1e9 + 7);
    }


    public:
    int numDecodings2(string s) {
        int n = s.size(), p = 1000000007;
        // f2 is the answer to sub string ending at position i; Initially i = 0.
        long f1 = 1, f2 = helper(s.substr(0,1));
        // DP to get f2 for sub string ending at position n-1;
        for (int i = 1; i < n; i++) {
            long f3 = (f2*helper(s.substr(i, 1)))+(f1*helper(s.substr(i-1, 2)));
            f1 = f2;
            f2 = f3%p;
        }
        return f2;
    }
private:
    int helper(string s) {
        if (s.size() == 1) {
            if (s[0] == '*') return 9;
            return s[0] == '0'? 0:1;
        }
        // 11-26, except 20 because '*' is 1-9
        if (s == "**")  
            return 15;
        else if (s[1] =='*') {
            if (s[0] =='1') return 9;
            return s[0] == '2'? 6:0;
        }
        else if (s[0] == '*') 
            return s[1] <= '6'? 2:1;
        else 
            // if two digits, it has to be in [10 26]; no leading 0
            return stoi(s) >= 10 && stoi(s) <= 26? 1:0; 
    }
};

int main()
{
    Solution s1;
    //string str = "**********1111111111";
    string str = "**********";
    int r = s1.numDecodings(str);
    int r2 = s1.numDecodings2(str);

    return 0;
}