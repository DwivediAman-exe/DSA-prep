#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/maximum-difference-between-node-and-its-ancestor/1/

Given a Binary Tree, you need to find the maximum value which you can get by subtracting the value of node B from the value of node A, where A and B are two nodes of the binary tree and A is an ancestor of B.

Input:
    5
 /    \
2      1
Output: 4
*/
/*
Method 1:
TC-O(N^2) SC-O(H) :
    Maintain a vector of ancestors.
*/

/*
Method 2:
TC-O(N) SC-O(H) :
*/
void maxDiffUtil(Node *root, int ances, int &ans)
{
    if (!root)
        return;
    ans = max(ans, ances - root->data);
    if (ances < root->data)
        ances = root->data;
    maxDiffUtil(root->left, ances, ans);
    maxDiffUtil(root->right, ances, ans);
}
// Function to return the maximum difference between any node and its ancestor.
int maxDiff(Node *root)
{
    int ans = INT_MIN;
    maxDiffUtil(root, -1000000, ans);
    return ans;
}