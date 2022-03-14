#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/construct-tree-1/1/

Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal.

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
*/
/*
Method 1:
TC-O(N^2) SC-O(1) :
*/
class Solution
{
public:
    Node *buildTreeUtil(int in[], int pre[], int l, int r, int &i)
    {

        if (l > r)
            return NULL;

        Node *root = new Node(pre[i++]);

        int m;

        for (int j = l; j <= r; j++)
        {
            if (in[j] == root->data)
            {
                m = j;
                break;
            }
        }

        root->left = buildTreeUtil(in, pre, l, m - 1, i);
        root->right = buildTreeUtil(in, pre, m + 1, r, i);

        return root;
    }

    Node *buildTree(int in[], int pre[], int n)
    {
        int i = 0;
        Node *root = buildTreeUtil(in, pre, 0, n - 1, i);
        return root;
    }
};
/*
Method 2:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    Node *buildTreeUtil(int in[], int pre[], int l, int r, int &i, unordered_map<int, int> &mp)
    {

        if (l > r)
            return NULL;

        Node *root = new Node(pre[i++]);

        int m = mp[root->data];

        root->left = buildTreeUtil(in, pre, l, m - 1, i, mp);
        root->right = buildTreeUtil(in, pre, m + 1, r, i, mp);

        return root;
    }

    Node *buildTree(int in[], int pre[], int n)
    {
        int i = 0;
        unordered_map<int, int> mp;
        for (int j = 0; j < n; j++)
        {
            mp[in[j]] = j;
        }
        Node *root = buildTreeUtil(in, pre, 0, n - 1, i, mp);
        return root;
    }
};