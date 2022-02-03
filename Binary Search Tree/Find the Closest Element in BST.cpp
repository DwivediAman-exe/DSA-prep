#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1/

Given a BST and an integer. Find the least absolute difference between any node value of the BST and the given integer.

Input:
        10
      /   \
     2    11
   /  \
  1    5
      /  \
     3    6
      \
       4
K = 13
Output: 2

Method 1:
TC-O(H) SC-O(H) :
*/

class Solution
{
public:
    // Function to find the least absolute difference between any node
    // value of the BST and the given integer.
    void helper(Node *r, int k, int &ans)
    {
        while (r != NULL)
        {
            ans = min(ans, abs(r->data - k));
            if (r->data > k)
            {
                r = r->left;
            }
            else if (r->data < k)
            {
                r = r->right;
            }
            else
            {
                ans = 0;
                return;
            }
        }
    }
    int minDiff(Node *root, int K)
    {
        int ans = INT_MAX;
        helper(root, K, ans);
        return ans;
    }
};