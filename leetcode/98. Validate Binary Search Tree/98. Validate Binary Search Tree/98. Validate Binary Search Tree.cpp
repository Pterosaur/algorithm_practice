// 98. Validate Binary Search Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//98. Validate Binary Search Tree
//Given a binary tree, determine if it is a valid binary search tree (BST).
//
//Assume a BST is defined as follows:
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.
//Example 1:
//    2
//   / \
//  1   3
//Binary tree [2,1,3], return true.
//Example 2:
//    1
//   / \
//  2   3
//Binary tree [1,2,3], return false.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
    int * pre_value;
public:
    Solution() {
        pre_value = NULL;
    }
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        if (root->left && ! isValidBST(root->left)) {
                return false;
        }
        if (pre_value && *pre_value >= root->val) {
            return false;
        }
        pre_value = &root->val;
        if (root->right && !isValidBST(root->right)) {
            return false;
        }
        return true;

    }
};

int main()
{
    Solution s1;
    TreeNode root(2);
    TreeNode left(1);
    TreeNode right(3);
    root.left = &left;
    root.right= &right;

    bool b = s1.isValidBST(&root);


    return 0;
}

