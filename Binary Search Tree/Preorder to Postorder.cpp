#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1/

Given an array arr[] of N nodes representing preorder traversal of BST. The task is to print its postorder traversal.
In Pre-Order traversal, the root node is visited before the left child and right child nodes.
Post-order traversal is one of the multiple methods to traverse a tree.

Input:
N = 5
arr[]  = {40,30,35,80,100}
Output: 35 30 100 80 40
*/
/*
Method 1:
TC-O(N) SC-O(N) :
*/

Node *post_orderUtil(int pre[], int size, int minVal, int maxVal, int &i)
{
    if (i == size)
        return NULL;
    if (pre[i] <= minVal || pre[i] >= maxVal)
        return NULL;

    Node *root = new Node();
    root->data = pre[i++];

    root->left = post_orderUtil(pre, size, minVal, root->data, i);
    root->right = post_orderUtil(pre, size, root->data, maxVal, i);

    return root;
}

// Function that constructs BST from its preorder traversal.
Node *post_order(int pre[], int size)
{
    int i = 0;
    return post_orderUtil(pre, size, INT_MIN, INT_MAX, i);
}