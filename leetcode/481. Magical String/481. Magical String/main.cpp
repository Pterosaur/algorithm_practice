//481. Magical String
//
//A magical string S consists of only '1' and '2' and obeys the following rules :
//
//The string S is magical because concatenating the number of contiguous occurrences of characters '1' and '2' generates the string S itself.
//
//The first few elements of string S is the following : S = "1221121221221121122……"
//
//If we group the consecutive '1's and '2's in S, it will be :
//
//1 22 11 2 1 22 1 22 11 2 11 22 ......
//
//and the occurrences of '1's or '2's in each group are :
//
//1 2	2 1 1 2 1 2 2 1 2 2 ......
//
//You can see that the occurrence sequence above is the S itself.
//
//Given an integer N as input, return the number of '1's in the first N number in the magical string S.
//
//Note: N will not exceed 100, 000.
//
//	Example 1 :
//	Input : 6
//	Output : 3
//	Explanation : The first 6 elements of magical string S is "12211" and it contains three 1's, so return 3.

#include <vector>
using namespace std;


class Solution {
private:
	char m_curr;
	char get_num() {
		return m_curr;
	}
	void reverse() {
		if (m_curr == 1) {
			m_curr = 2;
		}
		else {
			m_curr = 1;
		}
	}
public:
    int magicalString(int n) {
		if (n == 0) {
			return 0;
		}
		int count = 1;
		vector<char> buffer(100000);
		buffer[0] = m_curr = 1;
		vector<char>::iterator indicator = buffer.begin(), generator = buffer.begin() + 1;
		int indicated_num = *indicator;
		
		for (int i = 0; i < n - 1; i++) {
			if (indicated_num == 1) {
				reverse();
				*generator = get_num();
				if (*generator == 1) {
					count++;
				}
				generator++;
				indicator++;
				indicated_num = *indicator;
			}
			else {
				indicated_num--;
				*generator = get_num();
				if (*generator == 1) {
					count++;
				}
				generator++;
			}
		}
		return count;
    }
};


int main() {
	Solution s;
	s.magicalString(10000);
	return 0;
}