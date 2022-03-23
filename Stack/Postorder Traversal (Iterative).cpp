#include <bits/stdc++.h>
using namespace std;
/*
Question Link -

Given a binary tree. Find the postorder traversal of the tree without using recursion.

Input:
           1
         /   \
        2     3
      /  \
     4    5

Output: 4 5 2 3 1
*/
/*
Method 1:
TC-O(N) SC-O(N) : 2 stacks
*/
class Solution
{
public:
    vector<int> postOrder(Node *root)
    {
        stack<Node *> st1, st2;
        vector<int> res;

        st1.push(root);

        while (!st1.empty())
        {
            Node *temp = st1.top();
            st1.pop();

            if (temp->left)
                st1.push(temp->left);
            if (temp->right)
                st1.push(temp->right);

            st2.push(temp);
        }

        while (!st2.empty())
        {
            res.push_back(st2.top()->data);
            st2.pop();
        }

        return res;
    }
};
/*
Method 2:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    vector<int> postOrder(Node *root)
    {
        stack<Node *> st;
        vector<int> res;

        while (!st.empty() || root)
        {
            while (root)
            {
                if (root->right)
                    st.push(root->right);
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();

            if (root->right && !st.empty() && st.top() == root->right)
            {
                st.pop();
                st.push(root);
                root = root->right;
            }
            else
            {
                res.push_back(root->data);
                root = NULL;
            }
        }

        return res;
    }
};