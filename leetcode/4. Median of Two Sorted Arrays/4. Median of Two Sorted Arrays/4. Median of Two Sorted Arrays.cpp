// 4. Median of Two Sorted Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//4. Median of Two Sorted Arrays
//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
//Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
//Example 1:
//nums1 = [1, 3]
//nums2 = [2]
//
//The median is 2.0
//Example 2:
//nums1 = [1, 2]
//nums2 = [3, 4]
//
//The median is (2 + 3)/2 = 2.5

#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    double findIndex_even(vector<int>::iterator begin, int index) {
        return ((double)*(begin + index) + (double)*(begin + index- 1)) / 2;
    }
    double findIndex_odd(vector<int>::iterator begin, int index) {
        return ((double)*(begin + index));
    }
    double findIndex(
        vector<int>::iterator begin_1,
        vector<int>::iterator end_1,
        vector<int>::iterator begin_2,
        vector<int>::iterator end_2, 
        int index,
        bool is_odd) {
        if (begin_1 == end_1) {
            return is_odd ? findIndex_odd(begin_2, index) : findIndex_even(begin_2, index);
        }
        if (begin_2 == end_2) {
            return is_odd ? findIndex_odd(begin_1, index) : findIndex_even(begin_1, index);
        }
        if (index == 0) {
            if (is_odd) {
                std::min(*begin_1, *begin_2);
            }
            else {
                if (*begin_1 <= *begin_2) {
                    return (*begin_1 + std::min(
                        *begin_2, 
                        ((end_1 - begin_1) > 1) ? *(begin_1 + 1) : *begin_2));
                }
                else {
                    return findIndex(begin_2, end_2, begin_1, end_1, index, is_odd);
                }
            }
        }
        if (*(end_1 - 1) < *(begin_2)) {
            if ((end_1 - begin_1) >= index) {
                return is_odd ? findIndex_odd(begin_1, index) : findIndex_even(begin_1, index);
            }
            else {
                return findIndex_odd(begin_2, index - (end_1 - begin_1));
            }
        }
        else if (*(end_2 - 1) < *(begin_1)) {
            return findIndex(begin_2, end_2, begin_1, end_1, index);
        }
        int median_1 = *(begin_1 + (end_1 - begin_1) / 2);
        if (median_1 < *begin_2) {
            if (((end_1 - begin_1) / 2) > index) {

            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    }
};

int main()
{
    return 0;
}

