#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1/

Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

Input:
     10
    /  \
   2   -25
  / \  /  \
 20 1  3  4
Output: 32
*/
/*
Method 1:

TC-O(N) SC-O(H) :
*/
class Solution
{
public:
    int findMaxSumUtil(Node *root, int &ans)
    {
        if (!root)
            return 0;

        int lmax = findMaxSumUtil(root->left, ans);
        int rmax = findMaxSumUtil(root->right, ans);

        ans = max({ans, root->data + lmax, root->data + rmax, root->data + lmax + rmax});

        return max(root->data, root->data + max(lmax, rmax));
    }
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root)
    {
        int ans = INT_MIN;

        ans = max(ans, findMaxSumUtil(root, ans));

        return ans;
    }
};