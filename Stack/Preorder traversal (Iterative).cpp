#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/preorder-traversal-iterative/1/

Given a binary tree. Find the preorder traversal of the tree without using recursion.

Input:
           1
         /   \
        2     3
      /  \
     4    5
Output: 1 2 4 5 3
*/
/*
Method 1:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    vector<int> preOrder(Node *root)
    {
        stack<Node *> st;
        vector<int> res;

        st.push(root);

        while (!st.empty())
        {
            Node *temp = st.top();
            st.pop();

            res.push_back(temp->data);

            if (temp->right)
                st.push(temp->right);

            if (temp->left)
                st.push(temp->left);
        }

        return res;
    }
};