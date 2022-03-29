#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/burning-tree/1/

Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.

Input:
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
*/
/*
Method 1:
TC-O(N) SC-O(H) : BFS based.
*/
class Solution
{
public:
    int minTimeUtil(Node *root, int target, int &res, queue<Node *> &q)
    {
        if (!root)
            return 0;

        if (root->data == target)
        {

            if (root->left)
            {
                q.push(root->left);
            }
            if (root->right)
            {
                q.push(root->right);
            }

            return 1;
        }

        int lres = minTimeUtil(root->left, target, res, q);

        if (lres == 1)
        {
            int n = q.size();
            res++;

            while (n--)
            {
                Node *temp = q.front();
                q.pop();

                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }

            if (root->right)
                q.push(root->right);

            return 1;
        }

        int rres = minTimeUtil(root->right, target, res, q);

        if (rres == 1)
        {
            int n = q.size();
            res++;

            while (n--)
            {
                Node *temp = q.front();
                q.pop();

                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }

            if (root->left)
                q.push(root->left);

            return 1;
        }

        return 0;
    }

    int minTime(Node *root, int target)
    {
        queue<Node *> q;
        int res = 0;

        minTimeUtil(root, target, res, q);

        while (!q.empty())
        {
            int n = q.size();
            res++;

            while (n--)
            {
                Node *temp = q.front();
                q.pop();

                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }
        }

        return res;
    }
};

/*
Alternative Approach : Create an undirected graph by doing one traversal of the tree. Then apply BFS on the graph.
*/