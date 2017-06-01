//
//97. Interleaving String
//
//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
//For example,
//Given:
//s1 = "aabcc",
//s2 = "dbbca",
//
//When s3 = "aadbbcbcac", return true.
//When s3 = "aadbbbaccc", return false.
//

#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length()) {
			return false;
		}
		else if (s2.empty())
		{
			return s1 == s3;
		}
		else if (s1.empty()) {
			return s2 == s3;
		}
		vector<vector<bool> > record(s2.length() + 1, vector<bool>(s1.length() + 1, false));
		for (int i = 1; i <= s1.length(); i++) {
			if (s1[i-1] == s3[i-1]) {
				record[0][i] = true;
			}
			else {
				break;
			}
		}
		for (int i = 1; i <= s1.length(); i++) {
			if (s2[i-1] == s3[i-1]) {
				record[i][0] = true;
			}
			else {
				break;
			}
		}

		for (int i = 1; i <= s2.length(); i++) {
			for (int j = 1; j <= s1.length(); j++) {
				if (record[i - 1][j]) {
					record[i][j] = record[i][j] | (s3[i + j - 1] == s2[i - 1]);
				}
				if (record[i][j - 1]) {
					record[i][j] = record[i][j] | (s3[i + j - 1] == s1[j - 1]);
				}
			}
		}

		return record[s2.length()][s1.length()];
    }
};

int main() {
	Solution s;
	s.isInterleave("aa", "ab", "abaa");
	//s.isInterleave("aabcc", "dbbca", "aadbbcbcac");
	return 0;
}
