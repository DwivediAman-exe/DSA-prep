#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1/

Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

Input:
      1
   /    \
  2      3
Output: 2 1 3
*/
/*
Method 1:
TC-O(N*Log(N)) SC-O(N) :
*/
class Solution
{
public:
    void topViewUtil(Node *root, int c, int level, map<int, pair<int, int>> &mp)
    {
        if (!root)
            return;

        if (mp.find(c) == mp.end() || level < mp[c].first)
            mp[c] = {level, root->data};

        topViewUtil(root->left, c - 1, level + 1, mp);
        topViewUtil(root->right, c + 1, level + 1, mp);
    }

    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, pair<int, int>> mp;
        vector<int> res;

        topViewUtil(root, 0, 0, mp);

        for (auto x : mp)
            res.push_back(x.second.second);

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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        stack<int> left;
        vector<int> right, res;
        queue<pair<Node *, int>> q;
        int l = 0, r = 0;

        q.push({root, 0});

        while (!q.empty())
        {
            Node *temp = q.front().first;
            int dist = q.front().second;
            q.pop();

            if (dist < l)
            {
                left.push(temp->data);
                l = dist;
            }
            else if (dist > r)
            {
                right.push_back(temp->data);
                r = dist;
            }

            if (temp->left)
                q.push({temp->left, dist - 1});
            if (temp->right)
                q.push({temp->right, dist + 1});
        }
        while (!left.empty())
        {
            res.push_back(left.top());
            left.pop();
        }

        res.push_back(root->data);

        for (int i = 0; i < right.size(); i++)
        {
            res.push_back(right[i]);
        }

        return res;
    }
};