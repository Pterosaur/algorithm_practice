// 329. Longest Increasing Path in a Matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//329. Longest Increasing Path in a Matrix
//Given an integer matrix, find the length of the longest increasing path.
//
//From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
//
//Example 1:
//
//nums = [
//  [9,9,4],
//  [6,6,8],
//  [2,1,1]
//]
//Return 4
//The longest increasing path is [1, 2, 6, 9].
//
//Example 2:
//
//nums = [
//  [3,4,5],
//  [3,2,6],
//  [2,2,1]
//]
//Return 4
//The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
//
//Credits:
//Special thanks to @dietpepsi for adding this problem and creating all test cases.

#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
private:

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        
        int longest = 0;
        vector<vector<int> > record(matrix.size(), vector<int>(matrix[0].size(), 0));
        int directions[][2] = { {0,-1},{0,1},{-1,0}, {1,0} };
        std::function<int(int, int, int)> visit = [&](int x, int y, int before) {
            if (x < 0 || x >= matrix[0].size() || y < 0 || y >= matrix.size()) {
                return 0;
            }
            if (matrix[y][x] >= before) {
                return 0;
            }
            if (record[y][x]) {
                return record[y][x];
            }
            int cur_longest = 0;
            for (auto & direction : directions) {
                cur_longest = max(cur_longest, visit(x + direction[0], y + direction[1], matrix[y][x]));
            }
            record[y][x] = cur_longest + 1;
            return record[y][x];
        };

        for (int y = 0; y < record.size(); y++) {
            for (int x = 0; x < record[0].size(); x++) {
                if (record[y][x] == 0) {
                    visit(x, y, numeric_limits<int>::max());
                }
                longest = max(longest, record[y][x]);
            }
        }
        
        return longest;
    }
};

int main()
{
    Solution s1;
    vector<vector<int> > input = { {9,9,4},{6,6,8},{2,2,1} };
    //vector<vector<int> > input = { {7,8,9},{9,7,6},{7,2,3} };
    s1.longestIncreasingPath(input);
    return 0;
}

