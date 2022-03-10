#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1/

Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

Input:
n1 = 2 , n2 = 3
       1
      / \
     2   3
Output: 1
*/
/*
Method 1:
TC-O(N^2) SC-O(1) :
Store ancestors and return the last element common in both.
*/

/*
Method 2:
TC-O(N) SC-O(N) :
*/

class Solution
{
public:
    // Function to return the lowest common ancestor in a Binary Tree.
    Node *lca(Node *root, int n1, int n2)
    {
        if (!root)
            return NULL;

        if (root->data == n1 || root->data == n2)
            return root;

        Node *l = lca(root->left, n1, n2);
        Node *r = lca(root->right, n1, n2);

        if (l && r)
            return root;
        if (!l)
            return r;
        if (!r)
            return l;
        return NULL;
    }
};