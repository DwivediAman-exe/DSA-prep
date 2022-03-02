#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/

Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order:

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree.
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary.

Input:
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
      / \
     8   9

Output: 1 2 4 8 9 6 7 3

Method 1:
1) Find maximum sum from leaf to root in left subtree of X
2) Find maximum sum from leaf to root in right subtree of X.
3) Add the above two calculated values and X->data and compare the sum with the maximum value obtained so far and update the maximum value.
4) Return the maximum value.
The time complexity of above solution is O(n2)
*/
/*
Method 2:
TC-O(N) SC-O(H) :
*/
class Solution
{
public:
    void leftSide(Node *root, vector<int> &res)
    {
        if (!root)
            return;
        if (root->left || root->right)
            res.push_back(root->data);

        if (root->left)
            leftSide(root->left, res);
        else if (root->right)
            leftSide(root->right, res);
    }

    void leaf(Node *root, vector<int> &res)
    {
        if (!root)
            return;

        if (!root->left && !root->right)
            res.push_back(root->data);

        if (root->left)
            leaf(root->left, res);
        if (root->right)
            leaf(root->right, res);
    }

    void rightSide(Node *root, vector<int> &res)
    {
        if (!root)
            return;

        if (root->right)
            rightSide(root->right, res);
        else if (root->left)
            rightSide(root->left, res);

        if (root->left || root->right)
            res.push_back(root->data);
    }
    vector<int> boundary(Node *root)
    {
        vector<int> res;

        if (root == NULL)
            return res;
        res.push_back(root->data);
        leftSide(root->left, res);
        leaf(root->left, res);
        leaf(root->right, res);
        rightSide(root->right, res);

        return res;
    }
};
