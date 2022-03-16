#include <bits/stdc++.h>
using namespace std;
/*
Question Link -

Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.

Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4
*/
/*
Method 1:
TC-O(N*Log(N)) SC-O(N) :
Store in map with slope values as key.
*/

/*
Method 2:
TC-O(N) SC-O(N) :
*/
vector<int> diagonal(Node *root)
{
    vector<int> res;
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        root = q.front();
        q.pop();

        while (root)
        {
            res.push_back(root->data);
            if (root->left)
                q.push(root->left);
            root = root->right;
        }
    }

    return res;
}