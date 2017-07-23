// 145. Binary Tree Postorder Traversal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//145. Binary Tree Postorder Traversal
//Given a binary tree, return the postorder traversal of its nodes' values.
//
//For example:
//Given binary tree {1,#,2,3},
//   1
//    \
//     2
//    /
//   3
//return [3,2,1].
//
//Note: Recursive solution is trivial, could you do it iteratively?

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return vector<int>();
        }
        vector<int> result;
        result.reserve(128);

        stack<TreeNode *> visit_stack;
        visit_stack.push(root);
        while (!visit_stack.empty()) {
            TreeNode * node = visit_stack.top();
            if (node->left) {
                visit_stack.push(node->left);
            }
            else if (node->right) {
                visit_stack.push(node->right);
            }
            else {
                result.push_back(node->val);
                visit_stack.pop();
                if (!visit_stack.empty()) {
                    TreeNode * parent = visit_stack.top();
                    if (parent->left == node) {
                        parent->left = NULL;
                    }
                    else {
                        parent->right = NULL;
                    }
                }
            }
        }

        return result;
    }
};


int main()
{
    return 0;
}

