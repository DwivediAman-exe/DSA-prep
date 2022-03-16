#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1/

Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

Input:
      5
    /  \
   2    3
Output: 1
*/
/*
Method 1:
TC-O(N) SC-O(H) :
1 function to count total nodes, 1 to check property of heap and 1 to check if tree is complete.
To check if tree is complete assign index(2*i+1, 2*i+2) in each pass and compare with total nodes.
*/

/*
Method 2:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    bool isHeap(struct Node *root)
    {
        queue<Node *> q;
        q.push(root);
        bool child = true;

        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                Node *temp = q.front();
                q.pop();

                if (temp->left)
                {
                    if (!child)
                        return false;

                    if (temp->left->data < temp->data)
                        q.push(temp->left);
                    else
                        return false;
                }
                else
                    child = false;

                if (temp->right)
                {
                    if (!child)
                        return false;

                    if (temp->right->data < temp->data)
                        q.push(temp->right);
                    else
                        return false;
                }
                else
                    child = false;
            }
        }

        return true;
    }
};