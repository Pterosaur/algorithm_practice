// 124. Binary Tree Maximum Path Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//124. Binary Tree Maximum Path Sum
//
//Given a binary tree, find the maximum path sum.
//
//For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
//
//For example:
//Given the below binary tree,
//
//       1
//      / \
//     2   3
//Return 6.
//

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <limits>
#include <algorithm>

class Solution {
private:
    int m_max_path;
public:
    Solution() : m_max_path(std::numeric_limits<int>::min()){
    }

    bool _maxPathSum(TreeNode * root, int & partial_path) {
        if (root == NULL) {
            return false;
        }
        int max_path = root->val;
        partial_path = max_path;
        int left_path;
        if (_maxPathSum(root->left, left_path) && left_path > 0) {
            max_path += left_path;
            partial_path += left_path;
        }
        int right_path;
        if (_maxPathSum(root->right, right_path) && right_path > 0) {
            max_path += right_path;
            partial_path = std::max(partial_path, root->val + right_path);
        }
        if (max_path > m_max_path) {
            m_max_path = max_path;
        }
        return true;
    }


    int maxPathSum(TreeNode* root) {
        int partial_path = 0;
        _maxPathSum(root, partial_path);
        return m_max_path;
    }
};


int main()
{
    return 0;
}

