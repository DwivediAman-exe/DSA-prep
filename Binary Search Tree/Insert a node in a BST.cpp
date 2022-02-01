#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1/

Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST.
Note: If K is already present in the BST, don't modify the BST.

Input:
     2
   /   \
  1     3
K = 4
Output: 1 2 3 4

Method 1:
TC-O(H) SC-O(H) :
*/

Node *insert(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);

    if (key > root->data)
        root->right = insert(root->right, key);
    else if (key < root->data)
        root->left = insert(root->left, key);

    return root;
}
