//406. Queue Reconstruction by Height

//Suppose you have a random list of people standing in a queue.Each person is described by a pair of integers(h, k), 
//where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h.Write an algorithm to reconstruct the queue.
//
//Note:
//The number of people is less than 1, 100.
//Example
//Input :
//[[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]
//Output :
//	[[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		sort(people.begin(), people.end(), [](const pair<int, int> & a, const pair<int, int> & b) {
			if (a.first != b.first)
				return a.first > b.first;
			else
				return a.second < b.second;
		});
		for (int i = 0; i < people.size(); i++) {
			for (int j = i; j > people[j].second; j--) {
				swap(people[j], people[j - 1]);
			}
		}
		return people;
	}
};


int main() {
	vector<pair<int, int>> input = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
	Solution s1;
	s1.reconstructQueue(input);
	return 0;
}