// 295. Find Median from Data Stream.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//295. Find Median from Data Stream
//Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
//
//Examples: 
//[2,3,4] , the median is 3
//
//[2,3], the median is (2 + 3) / 2 = 2.5
//
//Design a data structure that supports the following two operations:
//
//void addNum(int num) - Add a integer number from the data stream to the data structure.
//double findMedian() - Return the median of all elements so far.
//For example:
//
//addNum(1)
//addNum(2)
//findMedian() -> 1.5
//addNum(3) 
//findMedian() -> 2

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <xfunctional>

using namespace std;

template<class Pr_>
void _heap_push(vector<int>::iterator begin, vector<int>::iterator back, Pr_ pr) {
    if (back <= begin) {
        return;
    }
    vector<int>::iterator parent = begin + (back - begin - 1) / 2;
    if (!pr(*back, *parent)) {
        swap(*parent, *back);
        _heap_push(begin, parent, pr);
    }
}


template<class Pr_>
void heap_push(vector<int>::iterator begin, vector<int>::iterator end, Pr_ pr) {
    _heap_push(begin, --end, pr);
}

template<class Pr_>
void _heap_pop(vector<int>::iterator begin, size_t cur ,size_t length, Pr_ pr) {
    if (cur > length) {
        return;
    }
    size_t left_pos = cur * 2 + 1;
    size_t right_pos = cur * 2 + 2;
    size_t greater_child = left_pos;
    if (right_pos < length) {
        greater_child = !pr(*(begin + left_pos), *(begin + right_pos)) ? left_pos : right_pos;
    }
    if (greater_child < length && !pr(*(begin + greater_child), *(begin + cur))) {
        swap(*(begin + greater_child), *(begin + cur));
        _heap_pop(begin, greater_child, length, pr);
    }
}

template<class Pr_>
void heap_pop(vector<int>::iterator begin, vector<int>::iterator end, Pr_ pr) {
    swap(*begin, *--end);
    _heap_pop(begin, 0, end - begin, pr);
}

template<class Pr_>
void heap_sort(vector<int>::iterator begin, vector<int>::iterator end, Pr_ pr) {

    //make
    for (int i = 1; i <= end - begin; i++) {
        heap_push(begin, begin + i, pr);
    }
    //sort
    for (int i = end - begin; i > 0; i--) {
        heap_pop(begin, begin + i, pr);
    }

}


void check() {
    vector<int> arr;
    for (int i = 0; i < 10; i++) {
        arr.push_back(i + 1);
    }
    vector<int> disorder_arr = arr;
    do {
        std::cout << "original : " << endl;
        copy(arr.begin(), arr.end(), ostream_iterator<int>(std::cout, " "));
        std::cout << endl;

        std::random_shuffle(disorder_arr.begin(), disorder_arr.end());
        std::cout << "disorder : " << endl;
        copy(disorder_arr.begin(), disorder_arr.end(), ostream_iterator<int>(std::cout, " "));
        std::cout << endl;


        heap_sort(disorder_arr.begin(), disorder_arr.end(), less<int>());
    } while (disorder_arr == arr);
    

}

class MedianFinder {
private:
    vector<int> less_half;
    vector<int> large_half;
public:
    /** initialize your data structure here. */

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (less_half.empty()) {
            less_half.push_back(num);
            return;
        }
        if (less_half.size() > large_half.size()) {
            if (less_half.front() < num) {
                large_half.push_back(num);
                push_heap(large_half.begin(), large_half.end(), greater<int>());
                return;
            }
            else {
                large_half.push_back(less_half.front());
                push_heap(large_half.begin(), large_half.end(), greater<int>());
                pop_heap(less_half.begin(), less_half.end(), less<int>());
                less_half.back() = num;
                push_heap(less_half.begin(), less_half.end(), less<int>());
            }
        }
        else {
            if (large_half.front() > num) {
                less_half.push_back(num);
                push_heap(less_half.begin(), less_half.end(), less<int>());
                return;
            }
            else {
                less_half.push_back(large_half.front());
                push_heap(less_half.begin(), less_half.end(), less<int>());
                pop_heap(large_half.begin(), large_half.end(), greater<int>());
                large_half.back() = num;
                push_heap(large_half.begin(), large_half.end(), greater<int>());
            }
        }

    }
    
    double findMedian() {
        if (less_half.size() == large_half.size()) {
            return ((double)less_half.front() + large_half.front()) / 2;
        }
        else if (less_half.size() < large_half.size()){
            return large_half.front();
        }
        else {
            return less_half.front();
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */


int main()
{
    MedianFinder obj;
    obj.addNum(1);
    double param_2 = obj.findMedian();
    obj.addNum(2);
    param_2 = obj.findMedian();
    obj.addNum(1);
    param_2 = obj.findMedian();
    return 0;
}

