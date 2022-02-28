#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1/

Given a binary tree, find if it is height balanced or not.
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree.

Input:
      1
    /
   2
    \
     3
Output: 0
*/
/*
Method 1:
TC - O(N^2) SC - O(H) :

*/

class Solution
{
public:
    int height(Node *root)
    {
        if (root == NULL)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if (!root)
            return true;

        int lh = height(root->left);
        int rh = height(root->right);

        if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return true;

        return false;
    }
};

/*
Method 2:
TC - O(N) SC - O(H) :
*/
class Solution
{
public:
    int isBalancedUtil(Node *root, bool &res)
    {
        if (!root)
            return 0;

        if (!res)
            return 0;

        int lh = isBalancedUtil(root->left, res);
        int rh = isBalancedUtil(root->right, res);

        if (abs(lh - rh) > 1)
            res = false;

        return max(lh, rh) + 1;
    }
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        bool res = true;

        isBalancedUtil(root, res);

        return res;
    }
};
