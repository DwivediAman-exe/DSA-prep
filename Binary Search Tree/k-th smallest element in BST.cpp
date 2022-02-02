#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1/

Given a BST and an integer K. Find the Kth Smallest element in the BST.

Input:
      2
    /   \
   1     3
K = 2
Output: 2

Method 1:
TC-O(N^2) SC-O(1) :

TC-O(N) SC-O(1) :
*/
class Solution
{
public:
    void inorder(Node *root, int k, int &res, int &count)
    {
        if (!root)
            return;

        inorder(root->left, k, res, count);

        if (count == k)
            return;

        res = root->data;
        count++;

        inorder(root->right, k, res, count);
    }

    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K)
    {

        int res, count = 0;

        inorder(root, K, res, count);

        if (count < K)
            return -1;

        return res;
    }
};