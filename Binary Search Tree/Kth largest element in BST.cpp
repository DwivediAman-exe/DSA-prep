#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1/

Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

Input:
      4
    /   \
   2     9
k = 2
Output: 4


Method 1:
TC-O(N) SC-O(N) :
*/
// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
public:
    void helper(Node *r, vector<int> &inorder)
    {
        if (!r)
            return;
        helper(r->left, inorder);
        inorder.push_back(r->data);
        helper(r->right, inorder);
    }
    int kthLargest(Node *root, int K)
    {
        vector<int> inorder;
        helper(root, inorder);
        return inorder[inorder.size() - K];
    }
};
/*
Method 2:
TC-O(H) SC-O(H) :
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
public:
    void reverse_inorder(Node *root, int k, int &res, int &count)
    {
        if (!root)
            return;

        reverse_inorder(root->right, k, res, count);

        if (count == k)
            return;

        res = root->data;
        count++;

        reverse_inorder(root->left, k, res, count);
    }
    int kthLargest(Node *root, int K)
    {
        int res, count = 0;

        reverse_inorder(root, K, res, count);

        return res;
    }
};