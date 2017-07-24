// 236. LowestCommonAncestor of a BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//236. Lowest Common Ancestor of a Binary Tree
//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
//
//According to the definition of LCA on Wikipedia: ¡°The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).¡±
//
//        _______3______
//       /              \
//    ___5__          ___1__
//   /      \        /      \
//   6      _2       0       8
//         /  \
//         7   4
//For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
    TreeNode * m_parent;
public:
    Solution() : m_parent(NULL) {
    }
    int Match(TreeNode * root, TreeNode * p, TreeNode * q) {
        if (!root) {
            return 0;
        }
        int result = 0;
        if (p == root) {
            result |= 1;
        }
        else if (root == q) {
            result |= 2;
        }
        result |= Match(root->left, p, q);
        result |= Match(root->right, p, q);
        if (result == 3 && NULL == m_parent) {
            m_parent = root;
        }
        return result;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Match(root, p, q);
        return m_parent;
    }
};

int main()
{
    return 0;
}

