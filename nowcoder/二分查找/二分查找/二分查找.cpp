// ���ֲ���.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//����һ���������飬����ͨ�����ö��ֲ��ҵķ�ʽ����λĳһԪ�أ����д���ֲ��ҵ��㷨���������в���ָ��Ԫ�ء�
//����һ����������A�����Ĵ�Сn��ͬʱ����Ҫ���ҵ�Ԫ��val���뷵�����������е�λ��(��0��ʼ)���������ڸ�Ԫ�أ�����-1������Ԫ�س��ֶ�Σ��뷵�ص�һ�γ��ֵ�λ�á�
//����������
//[1,3,5,7,9],5,3
//���أ�1

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

