#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1/

Given a BST, and a reference to a Node x in the BST. Find the Inorder Successor of the given node in the BST.

Input:
      2
    /   \
   1     3
K(data of x) = 2
Output: 3

Method 1:
TC-O(H) SC-O(1) :
*/

class Solution
{
public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    // Node*ans;
    Node *search(Node *root, Node *x, Node *&ans)
    {
        while (root->data != x->data)
        {
            if (!root)
                return NULL;
            if (root->data == x->data)
            {
                return root;
            }
            if (root->data > x->data)
            {
                ans = root;
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return root;
    }
    // returns the inorder successor of the Node x in BST (rooted at 'root')

    Node *inOrderSuccessor(Node *root, Node *x)
    {
        Node *ans = NULL;
        Node *t = search(root, x, ans);
        if (!t->right)
            return ans;
        else
        {
            t = t->right;
            while (t->left)
                t = t->left;
            return t;
        }
    }
};