#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1/

Given a Binary Search Tree (BST) and a range l-h(inclusive), count the number of nodes in the BST that lie in the given range.

    The values smaller than root go to the left side
    The values greater and equal to the root go to the right side

Input:
      10
     /  \
    5    50
   /    /  \
  1    40  100
l = 5, h = 45
Output: 3

Method 1:

TC-O(N) SC-O(H) :
*/
// Function to count number of nodes in BST that lie in the given range

int getCount(Node *root, int l, int h)
{
    if (root == NULL)
        return 0;

    if (root->data > h)
        return getCount(root->left, l, h);

    else if (root->data < l)
        return getCount(root->right, l, h);

    else
    {
        return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
    }
}