#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/construct-bst-from-post-order/1

Given postorder traversal of a Binary Search Tree, you need to construct a BST from postorder traversal. The output will be inorder traversal of the constructed BST.

Input:
6
1 7 5 50 40 10

Output:
1 5 7 10 40 50
*/
/*
Method 1:
TC-O(H) SC-O(H) :
*/

Node *constructTreeUtil(int post[], int l, int r, int &i)
{
    if (i < 0)
        return NULL;
    if (post[i] > l && post[i] < r)
    {
        Node *root = new Node(post[i--]);
        root->right = constructTreeUtil(post, root->data, r, i);
        root->left = constructTreeUtil(post, l, root->data, i);
    }
    else
        return NULL;
}

Node *constructTree(int post[], int size)
{
    int i = size - 1;
    return constructTreeUtil(post, INT_MIN, INT_MAX, i);
}