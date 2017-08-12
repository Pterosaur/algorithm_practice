// 二分查找.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//对于一个有序数组，我们通常采用二分查找的方式来定位某一元素，请编写二分查找的算法，在数组中查找指定元素。
//给定一个整数数组A及它的大小n，同时给定要查找的元素val，请返回它在数组中的位置(从0开始)，若不存在该元素，返回-1。若该元素出现多次，请返回第一次出现的位置。
//测试样例：
//[1,3,5,7,9],5,3
//返回：1

#include <vector>
#include <algorithm>
using namespace std;

class BinarySearch {
public:
    int getPos(vector<int> A, int n, int val) {
        if (A.empty()) {
            return -1;
        }
        int mid = n / 2;
        vector<int>::iterator begin = A.begin();
        while (n > 2) {
            if (*(begin + mid) >= val) {
                n /= 2;
                n += 1;

            }
            else {
                begin = begin + mid + 1;
                n /= 2;
            }

            mid = n / 2;
        }
        if (*begin == val) {
            return begin - A.begin();
        }
        if (n == 2 && *(begin + 1) == val) {
            return begin - A.begin() + 1;
        }
        return -1;
    }
};

int main()
{
    BinarySearch bs;
    vector<int> A = {1,3,3,3 ,5, 7,9};
    int pos = bs.getPos(A, A.size(), 3);
    auto itr = lower_bound(A.begin(), A.end(), 3);
    return 0;
}

