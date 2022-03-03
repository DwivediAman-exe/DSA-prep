#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1/

Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9
Output:
4 2 1 5 6 3 8 7 9

*/
/*
Method 1:
TC-O(N^2) SC-O(N) :
Calculate minDistance and maxDistance horizontally from root. Iterate from minDistance to maxDistance and print the ith vertical level.
*/

/*
Method 2:
TC-O(N * Log(N)) SC-O(N) :

Use Map.
*/

/*
Method 3:
TC-O(N) SC-O(N) :
*/

class Solution
{
public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        int mn = INT_MAX, mx = INT_MIN;

        queue<pair<Node *, int>> q;
        vector<int> res;
        unordered_map<int, vector<int>> mp;

        q.push({root, 0});

        while (!q.empty())
        {
            Node *temp = q.front().first;
            int dist = q.front().second;
            q.pop();

            mp[dist].push_back(temp->data);
            mn = min(mn, dist);
            mx = max(mx, dist);

            if (temp->left)
                q.push({temp->left, dist - 1});

            if (temp->right)
                q.push({temp->right, dist + 1});
        }

        for (int i = mn; i <= mx; i++)
        {
            vector<int> tmp = mp[i];
            for (auto x : tmp)
                res.push_back(x);
        }

        return res;
    }
};