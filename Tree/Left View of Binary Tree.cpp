#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1/

Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /   \    /    \
  4     5   6    7
   \
     8

Input:
   1
 /  \
3    2
Output: 1 3

*/
/*
Method 1:
TC-O(N) SC-O(N) :
*/
vector<int> leftView(Node *node)
{
    // Your code here
    vector<int> res;
    queue<Node *> q;
    q.push(node);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        if (temp)
        {
            res.push_back(temp->data);
            while (temp)
            {

                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                q.pop();

                temp = q.front();
            }
            q.push(NULL);
        }
        q.pop();
    }
    return res;
}

/*
Method 2:
TC-O(N) SC-O(H) :
*/
void leftViewUtil(Node *root, vector<int> &res, int level, int &maxLevel)
{
    if (!root)
        return;
    if (level > maxLevel)
    {
        res.push_back(root->data);
        maxLevel = level;
    }
    leftViewUtil(root->left, res, level + 1, maxLevel);
    leftViewUtil(root->right, res, level + 1, maxLevel);
}
// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> res;
    int maxLevel = -1;
    leftViewUtil(root, res, 0, maxLevel);
    return res;
}