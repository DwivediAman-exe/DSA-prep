#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1/

Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.

Input:
      1
    /   \
   2     3
Output: 1 2 3

Method 1:
TC-O(N* Log(N)) SC-O(N) :
*/

void inorder(Node *root, vector<int> &res)
{
    if (!root)
        return;
    inorder(root->left, res);

    res.push_back(root->data);

    inorder(root->right, res);
}

void makeBST(Node *root, vector<int> res, int &i)
{
    if (root == NULL)
        return;
    makeBST(root->left, res, i);
    root->data = res[i++];
    makeBST(root->right, res, i);
}

class Solution
{
public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST

    Node *binaryTreeToBST(Node *root)
    {
        vector<int> res;
        int i = 0;
        inorder(root, res);
        sort(res.begin(), res.end());
        makeBST(root, res, i);
        return root;
    }
};