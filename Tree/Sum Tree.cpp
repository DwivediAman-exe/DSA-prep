#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/sum-tree/1/

Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.

An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

Input:
    3
  /   \
 1     2

Output: 1
*/
/*
Method 1:
TC-O(N^2) SC-O(H) :
Calculate sum of subtrees and compare.
*/

/*
Method 2:
TC-O(N) SC-O(H) :
*/
class Solution
{
public:
    int isSumTreeUtil(Node *root, bool &ans)
    {
        if (!root)
            return 0;

        if (!root->left && !root->right)
            return root->data;

        int s = isSumTreeUtil(root->left, ans) + isSumTreeUtil(root->right, ans);

        if (s != root->data)
            ans = false;

        return s + root->data;
    }
    bool isSumTree(Node *root)
    {
        bool ans = true;
        isSumTreeUtil(root, ans);
        return ans;
    }
};