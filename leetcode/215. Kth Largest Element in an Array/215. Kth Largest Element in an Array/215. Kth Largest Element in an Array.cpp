// 215. Kth Largest Element in an Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//215. Kth Largest Element in an Array
//Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//For example,
//Given [3,2,1,5,6,4] and k = 2, return 5.
//
//Note: 
//You may assume k is always valid, 1 ¡Ü k ¡Ü array's length.

#include <vector>

using namespace std;

class Solution {
    vector<int>::iterator partial(vector<int>::iterator begin, vector<int>::iterator end, int mid) {
        while (true) {
            while ( *begin < mid) begin++;
            end--;
            while (mid < *end) end--;
            if (!(begin < end)) {
                return begin;
            }
            swap(*begin, *end);
            begin++;
        }
    }
    int findKthSmallest(vector<int>::iterator begin, vector<int>::iterator end, int k) {
        if (begin == end - 1) {
            return *begin;
        }
        vector<int>::iterator mid = partial(begin, end, *(begin + (end - begin)/2));
        if ((mid - begin) > k) {
            return findKthSmallest(begin, mid , k);
        }
        else {
            if (mid == begin) {
                mid++;
            }
            return findKthSmallest(mid, end, k - (mid - begin ));
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        //nth_element(nums.begin(), nums.begin() + (nums.size() - k), nums.end());
        //return  nums[(nums.size() - k)];
        return findKthSmallest(nums.begin(), nums.end(), nums.size() - k);
    }
};





int main()
{
    Solution s;
    vector<int> vet = {-1, 2, 0};
    s.findKthLargest(vet, 1);
    return 0;
}

