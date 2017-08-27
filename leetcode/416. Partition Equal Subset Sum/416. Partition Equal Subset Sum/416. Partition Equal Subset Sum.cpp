// 416. Partition Equal Subset Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//416. Partition Equal Subset Sum
//Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//
//Note:
//Each of the array element will not exceed 100.
//The array size will not exceed 200.
//Example 1:
//
//Input: [1, 5, 11, 5]
//
//Output: true
//
//Explanation: The array can be partitioned as [1, 5, 5] and [11].
//Example 2:
//
//Input: [1, 2, 3, 5]
//
//Output: false
//
//Explanation: The array cannot be partitioned into equal sum subsets.

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <bitset>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<bool> sub_sum;
        int target_sum = 0;
        for (auto i : nums) {
            target_sum += i;
        }
        if (target_sum & 1) {
            return false;
        }
        target_sum /= 2;
        if (target_sum > 0) {
            sub_sum.resize(target_sum + 1, false);
            sub_sum[0] = true;
        }
        for (auto n : nums) {
            for (int i = sub_sum.size() - 1; i >= 0; i--) {
                if (i - n < 0) {
                    break;
                }
                sub_sum[i] = sub_sum[i] | sub_sum[i - n];
            }

        }

        return sub_sum.back();
        
    }
};

int main()
{
    Solution s;
    //vector<int> vet = { 1,2,5 };
    vector<int> vet = {18, 40, 62, 33, 83, 64, 10, 92, 67, 31, 42, 51, 10, 97, 41, 7, 82, 71, 80, 81, 41, 38, 88, 25, 38, 89, 24, 89, 90, 12, 97, 21, 22, 85, 11, 59, 83, 6, 51, 47, 32, 82, 83, 100, 29, 78, 36, 32, 1, 31, 36, 19, 35, 3, 36, 21, 24, 93, 42, 33, 10, 26, 2, 39, 36, 62, 85, 24, 41, 5, 66, 53, 7, 1, 59, 53, 40, 59, 41, 95, 7, 67, 20, 29, 80, 59, 49, 49, 51, 90, 13, 52, 6, 90, 5, 6, 31, 81, 95, 26 };
    bitset<100> b;
    s.canPartition(vet);
    return 0;
}

