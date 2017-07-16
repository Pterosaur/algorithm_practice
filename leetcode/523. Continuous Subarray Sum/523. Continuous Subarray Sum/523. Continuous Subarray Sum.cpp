// 523. Continuous Subarray Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, that is, sums up to n*k where n is also an integer.
//
//Example 1:
//Input: [23, 2, 4, 6, 7],  k=6
//Output: True
//Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
//Example 2:
//Input: [23, 2, 6, 4, 7],  k=6
//Output: True
//Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> map;
        if (nums.empty()) {
            return false;
        }
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            sum += num;
            
            if (map.end() != map.find(k ? (sum % k) : sum)) {
                return true;
            }
            map.insert(k ? ((sum - num) % k) : sum - num);

        }
        return false;
    }
};

int main()
{
    Solution s1;
    std::vector<int> input = {1,2, 3};
    bool result = s1.checkSubarraySum(input, 5);
    int r = 1 % -1;
    return 0;
}

