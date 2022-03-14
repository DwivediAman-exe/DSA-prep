#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1/

Given a binary tree and two node values your task is to find the minimum distance between them.

Input:
        1
      /  \
     2    3
a = 2, b = 3
Output: 2
*/
/*
Method 1:
TC-O(N) SC-O(H) :
*/
class Solution
{
public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node *lca(Node *root, int n1, int n2)
    {
        if (root == NULL)
            return NULL;
        if (root->data == n1 || root->data == n2)
            return root;
        Node *left = lca(root->left, n1, n2);
        Node *right = lca(root->right, n1, n2);
        if (left && right)
            return root;
        if (left)
            return left;
        else
            return right;
    }
    int help(Node *root, int k, int l)
    {
        if (root == NULL)
            return -1;
        if (root->data == k)
            return l;
        int le = help(root->left, k, l + 1);
        if (le == -1)
            return help(root->right, k, l + 1);
        return le;
    }
    int findDist(Node *root, int a, int b)
    {
        Node *lc = lca(root, a, b);
        int le = help(lc, a, 0);
        int ri = help(lc, b, 0);
        return le + ri;
    }
};
/*
Method 2:
TC-O(N) SC-O(H) : Wouldn't work in case of multiple nodes of same  value.
*/

class Solution
{
public:
    int findDistUtil(Node *root, int a, int b, int &ans)
    {
        if (!root)
            return 0;

        int ldist = findDistUtil(root->left, a, b, ans);
        int rdist = findDistUtil(root->right, a, b, ans);

        if (root->data == a || root->data == b)
        {
            if (ldist || rdist)
            {
                ans = max(ldist, rdist);
                return 0;
            }
            else
                return 1;
        }

        else if (ldist && rdist)
        {
            ans = ldist + rdist;
            return 0;
        }
        else if (ldist || rdist)
        {
            return max(ldist, rdist) + 1;
        }

        return 0;
    }
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node *root, int a, int b)
    {
        int ans = 0;

        findDistUtil(root, a, b, ans);

        return ans;
    }
};