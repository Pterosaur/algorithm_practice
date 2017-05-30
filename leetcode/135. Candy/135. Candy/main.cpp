//
//135. Candy
//
//There are N children standing in a line.Each child is assigned a rating value.
//
//You are giving candies to these children subjected to the following requirements :
//
//Each child must have at least one candy.
//Children with a higher rating get more candies than their neighbors.
//
//


#include <vector>

using namespace std;

class Solution {
		enum state{
			increased,
			decreased,
			equal,
		} ;
		state detect_state(int previous, int later) {
			if (previous < later) {
				return increased;
			}
			else if (previous > later) {
				return decreased;
			}
			else {
				return equal;
			}
		}
public:
    int candy(vector<int>& ratings) {
		if (ratings.empty()) {
			return 0;
		}
		if (ratings.size() == 1) {
			return 1;
		}
		int sum = 1;
		int cur_candy = 1;
		int last_candy = 1;
		state last_state =  detect_state(ratings[0], ratings[1]);

		for (int i = 1; i < ratings.size(); i++) {
			state cur_state = detect_state(ratings[i - 1], ratings[i]);
			if (cur_state == last_state && cur_state != equal) {
				++cur_candy;
			}
			else if (cur_state == equal) {
				if (cur_candy < last_candy) {
					sum -= cur_candy;
					sum += last_candy;
				}
				last_candy = 1;
				cur_candy = 1;
			}
			else if (cur_state == increased) {
				if (cur_candy < last_candy) {
					sum -= cur_candy;
					sum += last_candy;
				}
				last_candy = 1;
				cur_candy = 2;
			}
			else if (cur_state == decreased){
				last_candy = cur_candy;
				i--;
				sum -= cur_candy;
				cur_candy = 1;
			}
			last_state = cur_state;
			sum += cur_candy;
		}
		if (cur_candy < last_candy) {
			sum -= cur_candy;
			sum += last_candy;
		}
		return sum;
    }
};

int main() {
	Solution s1;
	vector<int> rating = {1,3,4, 3, 2, 1};
	//vector<int> rating = { 4,2,3,4,1 };
	s1.candy(rating);
	return 0;
}