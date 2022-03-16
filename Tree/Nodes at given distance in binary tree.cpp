#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1/

Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. No parent pointers are available.

Input:
          20
        /    \
      8       22
    /   \
   4    12
       /   \
      10    14
Target Node = 8
K = 2
Output: 10 14 22
*/
/*
Method 1:
TC-O(N*Log(N)) SC-O(H) :
*/
class Solution
{
private:
public:
    void getNodesDownward(Node *root, int k, vector<int> &res)
    {
        if (!root || k < 0)
            return;

        if (k == 0)
        {
            res.push_back(root->data);
            return;
        }

        else
        {
            getNodesDownward(root->left, k - 1, res);
            getNodesDownward(root->right, k - 1, res);
        }
    }

    int KDistanceNodesUtil(Node *root, int target, int k, vector<int> &res)
    {
        if (!root)
            return -1;

        if (root->data == target)
        {
            getNodesDownward(root, k, res);
            return 1;
        }

        int lres = KDistanceNodesUtil(root->left, target, k, res);
        int rres = KDistanceNodesUtil(root->right, target, k, res);

        if (lres != -1 || rres != -1)
        {
            if (lres != -1)
            {
                int dist = lres;
                if (dist == k)
                {
                    res.push_back(root->data);
                }
                else
                    getNodesDownward(root->right, k - dist - 1, res);
                return dist + 1;
            }
            if (rres != -1)
            {
                int dist = rres;
                if (dist == k)
                {
                    res.push_back(root->data);
                }
                else
                    getNodesDownward(root->left, k - dist - 1, res);
                return dist + 1;
            }
        }

        return -1;
    }

    vector<int> KDistanceNodes(Node *root, int target, int k)
    {
        vector<int> res;
        KDistanceNodesUtil(root, target, k, res);
        sort(res.begin(), res.end());

        return res;
    }
};