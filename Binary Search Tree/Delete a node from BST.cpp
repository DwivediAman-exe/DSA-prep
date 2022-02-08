#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1/

Given a Binary Search Tree and a node value X. Delete the node with the given value X from the BST. If no node with value x exists, then do not make any change.

Input:
      2
    /   \
   1     3
X = 12
*/
/*
Method 1:
TC-O(H) SC-O(H) :
*/

// Function to find Inorder Successor.
Node *find_inorder_successor(Node *root)
{
    Node *r = root->right;

    while (r->left)
        r = r->left;

    return r;
}

// Function to delete a node from BST.

Node *deleteNode(Node *root, int x)
{
    if (root == NULL)
        return NULL;

    if (root->data == x)
    {
        if (!root->left && !root->right) // if node to be deleted is leaf node.
        {
            return NULL;
        }
        else if (!root->left || !root->right) // if node to be deleted has one child.
        {
            if (root->left)
                return root->left;
            else
                return root->right;
        }
        else // if node to be deleted has both children.
        {
            Node *inorder_successor = find_inorder_successor(root);
            root->data = inorder_successor->data;
            root->right = deleteNode(root->right, inorder_successor->data);
            return root;
        }
    }
    else if (root->data < x)
        root->right = deleteNode(root->right, x);
    else
        root->left = deleteNode(root->left, x);
}