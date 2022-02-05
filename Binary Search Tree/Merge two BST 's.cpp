#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1/

Given two BSTs, return elements of both BSTs in sorted form.

Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7
*/
/*
Method 1:
TC-O(M+N) SC-O(M + N) :
Create 2 vectors to store the inorder traversal of both the BSTs and merge the two sorted arrays.
*/
/*
Method 2:
TC-O(M+N) SC-O(H1 + H2) :
*/
class Solution
{
public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        Node *curr1 = root1, *curr2 = root2;
        stack<Node *> st1, st2;
        vector<int> res;

        while (curr1 || curr2 || !st1.empty() || !st2.empty())
        {
            while (curr1)
            {
                st1.push(curr1);
                curr1 = curr1->left;
            }

            while (curr2)
            {
                st2.push(curr2);
                curr2 = curr2->left;
            }

            if (!st1.empty() || !st2.empty())
            {
                if ((st2.empty()) || (!st1.empty() && st1.top()->data <= st2.top()->data))
                {
                    curr1 = st1.top();
                    st1.pop();
                    res.push_back(curr1->data);
                    curr1 = curr1->right;
                }
                else
                {
                    curr2 = st2.top();
                    st2.pop();
                    res.push_back(curr2->data);
                    curr2 = curr2->right;
                }
            }
        }

        return res;
    }
};
