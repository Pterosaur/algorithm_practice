// 297. Serialize and Deserialize BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//297. Serialize and Deserialize Binary Tree
//Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
//
//Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
//
//For example, you may serialize the following tree
//
//    1
//   / \
//  2   3
//     / \
//    4   5
//as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
//Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
//
//Credits:
//Special thanks to @Louis1992 for adding this problem and creating all test cases.

#include <string>
#include <vector>
#include <queue>
#include <list>

using namespace std;


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

struct Unit {
    bool m_valid;
    int m_value;
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return string();
        }
        vector<Unit> buffer;
        buffer.reserve(128);
        queue<TreeNode *> visit_queue;
        visit_queue.push(root);
        while (!visit_queue.empty()) {
            TreeNode * node = visit_queue.front();
            visit_queue.pop();
            if (node == NULL) {
                buffer.push_back(Unit{ false, 0 });
            }
            else {
                buffer.push_back(Unit{true, node->val });
                visit_queue.push(node->left);
                visit_queue.push(node->right);
            }
        }
        string result;
        result.resize(buffer.size() * sizeof(Unit));
        copy(buffer.begin(), buffer.end(), (Unit *)&result[0]);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }

        vector<Unit> buffer;
        buffer.resize(data.size() / sizeof(Unit));
        copy((Unit *)&data[0], ((Unit *)(&data[0])) + data.size() / sizeof(Unit), buffer.begin());
        vector<Unit>::iterator visit_itr = buffer.begin();

        TreeNode * node = new TreeNode(visit_itr->m_value);
        visit_itr++;

        queue<TreeNode *> visit_queue;
        visit_queue.push(node);

        while ( ! visit_queue.empty()) {
            TreeNode * dnode = visit_queue.front();
            visit_queue.pop();

            if (visit_itr == buffer.end()) {
                break;
            }
            if (visit_itr->m_valid) {
                dnode->left = new TreeNode(visit_itr->m_value);
                visit_queue.push(dnode->left);
            }
            visit_itr++;

            if (visit_itr == buffer.end()) {
                break;
            }
            if (visit_itr->m_valid) {
                dnode->right = new TreeNode(visit_itr->m_value);
                visit_queue.push(dnode->right);
            }
            visit_itr++;
        }

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


int main()
{
    return 0;
}

