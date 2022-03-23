#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/inorder-traversal-iterative/1/

Given a binary tree. Find the inorder traversal of the tree without using recursion.

Input:
           1
         /    \
       2       3
      /   \
    4     5
Output: 4 2 5 1 3
*/
/*
Method 1:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    vector<int> inOrder(Node *root)
    {
        stack<Node *> st;
        vector<int> res;

        while (root || !st.empty())
        {
            while (root)
            {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();

            res.push_back(root->data);

            root = root->right;
        }

        return res;
    }
};