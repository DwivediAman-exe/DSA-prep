#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/delete-nodes-greater-than-k/1/

Given a BST and a value k, the task is to delete the nodes having values greater than or equal to x.

Input:
    4
   / \
  1   9
k = 2
Output:
1
*/
/*
Method 1:
TC-O(N) SC-O(1) :
*/

class Solution
{
public:
    /*The function should return the root of the modified tree*/
    Node *deleteNode(Node *root, int k)
    {
        if (!root)
            return NULL;
        if (root->data >= k)
        {
            return deleteNode(root->left, k);
        }
        else
        {
            root->right = deleteNode(root->right, k);
        }
    }
};