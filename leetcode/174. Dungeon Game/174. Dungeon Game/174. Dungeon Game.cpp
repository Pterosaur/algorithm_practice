// 174. Dungeon Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"




//174. Dungeon Game
//
//The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.
//
//The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
//
//Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
//
//In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
//
//
//Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
//
//For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
//
//-2 (K)	-3	3
//-5	-10	1
//10	30	-5 (P)
//
//Notes:
//
//The knight's health has no upper bound.
//Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int M = dungeon.size();
        if (M == 0) {
            return 1;
        }
        int N = dungeon.front().size();
        if (N == 0) {
            return 1;
        }

        vector<vector<int> > health_map(M, vector<int>(N, std::numeric_limits<int>::max()));

        health_map[M - 1][N - 1] = (dungeon[M - 1][N - 1] > 0) ? 1 : (1 - dungeon[M - 1][N - 1]);

        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                if (i != 0) {
                    int expected = health_map[i][j] - dungeon[i - 1][j];
                    health_map[i - 1][j] = min(health_map[i - 1][j],  (expected <= 0) ? 1 : expected);
                }
                if (j != 0) {
                    int expected = health_map[i][j] - dungeon[i][j - 1];
                    health_map[i][j - 1] = min(health_map[i][j - 1], (expected <= 0) ? 1 : expected);
                }
            }
        }
        
        return health_map[0][0];
    }
};



int main()
{
    return 0;
}

