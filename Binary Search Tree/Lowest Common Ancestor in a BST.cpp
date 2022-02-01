#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1/

Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.

Input:
              5
           /    \
         4       6
        /         \
       3           7
                    \
                     8
n1 = 7, n2 = 8
Output: 7

Method 1:
TC-O(H) SC-O(H) :
*/

Node *LCA(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;

    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
    else if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);

    return root;
}
