#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1/

Given a Binary Tree, write a function to populate next pointer for all nodes. The next pointer for every node should be set to point to inorder successor.

Input:
           10
       /  \
      8    12
     /
    3


Output: 3->8 8->10 10->12 12->-1
*/
/*
Method 1:

TC-O(N) SC-O(H) :
*/
class Solution
{
public:
    void populateNextUtil(Node *root, Node *&prev)
    {
        if (!root)
            return;

        populateNextUtil(root->left, prev);

        if (prev)
            prev->next = root;

        prev = root;

        populateNextUtil(root->right, prev);
    }

    void populateNext(Node *root)
    {
        Node *prev = NULL;
        populateNextUtil(root, prev);
    }
};