#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/maximum-path-sum/1/

Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one leaf node to another leaf node.

Note: Here Leaf node is a node which is connected to exactly one different node.

Input:
           3
         /    \
       4       5
      /  \
    -10   4
Output: 16
*/
/*
Method 1:
TC-O(N^2) SC-O(1) :
*/

/*
Method 2:
TC-O(N) SC-O(H) :
*/

class Solution
{
public:
    int maxPathSumUtil(Node *root, int &res)
    {
        if (!root)
            return INT_MIN;

        if (!root->left && !root->right)
            return root->data;

        int leftSum = maxPathSumUtil(root->left, res);
        int rightSum = maxPathSumUtil(root->right, res);

        if (root->left && root->right)
            res = max(res, leftSum + root->data + rightSum);

        return max(leftSum, rightSum) + root->data;
    }

    int maxPathSum(Node *root)
    {
        int res = INT_MIN;

        int ans = maxPathSumUtil(root, res);

        if (root->left && root->right)
            return res;
        else
            return max(ans, res);
    }
};