// 51. N-Queens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//51. N-Queens
//Follow up for N-Queens problem.
//
//Now, instead outputting board configurations, return the total number of distinct solutions.

#include<vector>
using namespace std;

class Solution {
private:
    int m_total;

    bool can_set(int column, int raw, vector<vector<bool> > & board) {
        //up
        for (int i = 0; i < column; i++) {
            if (board[i][raw]) {
                return false;
            }
        }
        //left
        int i = column, j = raw;
        while (i >= 0 && j >= 0) {
            if (board[i][j]) {
                return false;
            }
            i--;
            j--;
        }
        
        //right
        i = column, j = raw;
        while (i >= 0 && j < board.size()) {
            if (board[i][j]) {
                return false;
            }
            i--;
            j++;
        }

        return true;
    }

    void search_queue(int column, int n, vector<vector<bool> > & board) {
        if (column == n) {
            m_total++;
        }
        for (int i = 0; i < n; i++) {
            if (can_set(column, i, board)) {
                board[column][i] = true;
                search_queue(column + 1, n, board);
                board[column][i] = false;
            }
        }
    }
public:
    int totalNQueens(int n) {
        if (n == 0) {
            return 0;
        }
        m_total = 0;
        vector<vector<bool> > board(n, vector<bool>(n, false));
        search_queue(0, n, board);
        return m_total;
    }
};

int main()
{
    Solution s1;
    int t = s1.totalNQueens(2);
    return 0;
}

