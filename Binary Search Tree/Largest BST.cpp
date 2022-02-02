#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/largest-bst/1/

Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1

Method 1:
TC-O(N) SC-O(H) :
*/

struct bst
{
    int size;
    int ans;
    int min;
    int max;
    bool isBST;
};

class Solution
{
public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST

    bst helper(Node *root)
    {
        if (root == NULL)
            return {0, 0, INT_MAX, INT_MIN, true};

        if (!root->left && !root->right)
            return {1, 1, root->data, root->data, true};

        bst ltree = helper(root->left);
        bst rtree = helper(root->right);

        bst res;
        res.size = ltree.size + rtree.size + 1;

        if (ltree.isBST && rtree.isBST)
        {
            if ((ltree.max < root->data) && (rtree.min > root->data))
            {
                res.ans = ltree.size + rtree.size + 1;
                res.min = min({ltree.min, rtree.min, root->data});
                res.max = max({ltree.max, rtree.max, root->data});
                res.isBST = true;

                return res;
            }
        }

        res.ans = max(ltree.ans, rtree.ans);
        res.isBST = false;

        return res;
    }

    int largestBst(Node *root)
    {
        if (!root)
            return 0;

        bst res = helper(root);

        return res.ans;
    }
};