#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/

Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight pointer for the same.

Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.
       10                    10 ------> NULL
      / \                 /      \
     3   5       =>     3 ------> 5 --------> NULL
    / \     \          /  \         \
   4   1   2          4 --> 1 -----> 2 -------> NULL


Input:
     3
   /  \
  1    2
Output:
3 1 2
1 3 2
*/
/*
Method 1:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    // Function to connect nodes at same level.
    void connect(Node *root)
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();

            while (n--)
            {
                Node *temp = q.front();
                q.pop();

                if (n == 0)
                {
                    temp->nextRight = NULL;
                }
                else
                {
                    temp->nextRight = q.front();
                }

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
    }
};
/*
Method 2:
TC-O(N) SC-O(H) :
*/