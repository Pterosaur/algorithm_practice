// 149. Max Points on a Line.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

/**
* Definition for a point.
* struct Point {
*     int x;
*     int y;
*     Point() : x(0), y(0) {}
*     Point(int a, int b) : x(a), y(b) {}
* };
*/

#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

struct Line {
    int a;
    int b;
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
              
    }
};


int main()
{
    return 0;
}

