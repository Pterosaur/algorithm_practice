// 15. 3Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
//Note: The solution set must not contain duplicate triplets.
//
//
//For example, given array S = [-1, 0, 1, 2, -1, -4],
//
//A solution set is:
//[
//  [-1, 0, 1],
//  [-1, -1, 2]
//]

#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct ksum {
    std::vector<int> m_set;
    ksum(std::vector<int> && set) : m_set(set){}
    bool operator < (struct ksum other) const{
        for (int i = 0; i < m_set.size(); i++) {
            if (m_set[i] < other.m_set[i]) {
                return true;
            }
        }
        return false;
    }
};

void twoSum(
    std::vector<int>::iterator input_begin,
    std::vector<int>::iterator input_end,
    int target,
    std::set<std::vector<int> > & output) {
    input_end--;
    while (input_begin < input_end) {
        int sum = *input_begin + *input_end;
        if (sum == target) {
            output.insert({ *input_begin, *input_end });
            input_begin++;
            input_end--;
        }
        else if (sum < target) {
            input_begin++;
        }
        else {
            input_end--;
        }
    }
}

void _KSum(
    std::vector<int>::iterator input_begin,
    std::vector<int>::iterator input_end,
    int k,
    int target,
    std::set<std::vector<int> > & output) {
    if (k < 2 || (input_end - input_begin) < k) {
        return;
    }
    else if (k > 2) {
        for (auto itr = input_begin; itr < input_end; itr++) {
            if (itr > input_begin && *itr == *(itr - 1)) {
                continue;
            }
            std::set<std::vector<int> > suboutput;
            _KSum(itr + 1, input_end, k - 1, target - *itr, suboutput);
            for (auto & tuple : suboutput) {
                std::vector<int> vet = tuple;
                vet.push_back(*itr);
                output.insert(vet);
            }
        }
    }
    else {
        twoSum(input_begin, input_end, target, output);
    }
}

void KSum(std::vector<int> & input, std::vector<std::vector<int> > & output, int k, int target) {
    std::set<vector<int> > result_set;
    std::sort(input.begin(), input.end());
    _KSum(input.begin(), input.end(), k, target, result_set);
    for (auto tuple : result_set) {
        output.push_back(tuple);
    }
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>  result;
        KSum(nums, result, 3, 0);
        return result;
    }
};


int main()
{
    Solution s1;
    vector<int> input = { -1, 0, 1, 2, -1, -4 };
    auto output = s1.threeSum(input);
    return 0;
}

