#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/node-at-distance/1/

Given a Binary Tree and a positive integer k. The task is to count all distinct nodes that are distance k from a leaf node. A node is at k distance from a leaf if it is present k levels above the leaf and also, is a direct ancestor of this leaf node. If k is more than the height of Binary Tree, then nothing should be counted.

Input:
        1
      /   \
     2     3
   /  \   /  \
  4   5  6    7
          \
          8
K = 2
Output: 2
*/
/*
Method 1:

TC-O(N) SC-O(H) :
*/
void printKDistantfromLeafUtil(Node *r, int k, unordered_set<Node *> &s, vector<Node *> v)
{
    if (!r)
        return;

    v.push_back(r);

    if (!r->left && !r->right)
    {
        if (v.size() > k)
        {
            s.insert(v[v.size() - k - 1]);
        }
        return;
    }

    printKDistantfromLeafUtil(r->left, k, s, v);
    printKDistantfromLeafUtil(r->right, k, s, v);
}
// Function to return count of nodes at a given distance from leaf nodes.
int printKDistantfromLeaf(Node *root, int k)
{
    if (!root)
        return 0;
    unordered_set<Node *> s;
    vector<Node *> v;

    printKDistantfromLeafUtil(root, k, s, v);

    return s.size();
}