// 99. Recover Binary Search Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//99. Recover Binary Search Tree
//
//Two elements of a binary search tree (BST) are swapped by mistake.
//
//Recover the tree without changing its structure.
//
//Note:
//A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <algorithm>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int * m_previous;
    int * m_less;
    int * m_large;
public:
    Solution() {
        static int min_int = (std::numeric_limits<int>::min());
        m_previous = &min_int;
        m_less = NULL;
        m_large = NULL;
    }
    void mid_visit(TreeNode * root) {
        if (!root) {
            return;
        }
        mid_visit(root->left);
        if (root->val < *m_previous) {
            if (m_large == NULL) {
                m_large = m_previous;
            }
            m_less = &root->val;
        }
        m_previous = &root->val;
        mid_visit(root->right);
    }
    void recoverTree(TreeNode* root) {
        mid_visit(root);
        std::swap(*m_large, *m_less);
    }
};

int main()
{
    return 0;
}

