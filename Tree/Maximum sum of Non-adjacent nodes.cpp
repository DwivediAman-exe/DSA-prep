#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1/

Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
*/
/*
Method 1: DP
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    unordered_map<Node *, int> mp;
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root)
    {
        if (!root)
            return 0;

        if (mp.find(root) != mp.end())
            return mp[root];

        int inc_root = root->data;

        if (root->left)
        {
            inc_root += getMaxSum(root->left->left) + getMaxSum(root->left->right);
        }
        if (root->right)
        {
            inc_root += getMaxSum(root->right->left) + getMaxSum(root->right->right);
        }

        int exc_root = getMaxSum(root->left) + getMaxSum(root->right);

        return mp[root] = max(inc_root, exc_root);
    }
};
/*
Method 2:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    // In pair first value will be the max sum including root and second value will be max sum excluding root.
    pair<int, int> getMaxSumUtil(Node *root)
    {
        if (!root)
            return {0, 0};

        pair<int, int> p, s1, s2;

        s1 = getMaxSumUtil(root->left);
        s2 = getMaxSumUtil(root->right);

        p.first = root->data + s1.second + s2.second;
        p.second = max(s1.first, s1.second) + max(s2.first, s2.second);

        return p;
    }
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root)
    {
        pair<int, int> p = getMaxSumUtil(root);

        return max(p.first, p.second);
    }
};