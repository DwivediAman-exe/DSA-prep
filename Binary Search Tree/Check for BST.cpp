#include <bits/stdc++.h>
using namespace std;

/*
Question Link - https://practice.geeksforgeeks.org/problems/check-for-bst/1/

Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Input:
   2
 /    \
1      3
Output: 1

Method 1:
TC-O(N) SC-O(H) :
*/
class Solution
{
public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBSTUtil(Node *root, int min_rnge, int max_rnge)
    {
        if (!root)
            return true;
        if (root->data <= min_rnge || root->data >= max_rnge)
        {
            return false;
        }

        return isBSTUtil(root->left, min_rnge, root->data) &&
               isBSTUtil(root->right, root->data, max_rnge);
    }
    bool isBST(Node *root)
    {
        if (!root)
            return true;
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
};