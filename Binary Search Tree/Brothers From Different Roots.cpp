#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1/

Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x. Your task is to complete the function countPairs(), that returns the count of all pairs from both the BSTs whose sum is equal to x.

Input:
BST1:
       5
     /   \
    3     7
   / \   / \
  2   4 6   8

BST2:
       10
     /    \
    6      15
   / \    /  \
  3   8  11   18

x = 16
Output:
3

Method 1:
TC-O(N) SC-O(N) :
*/
class Solution
{
    void inorder(Node *root, vector<int> &tree)
    {
        if (!root)
            return;
        inorder(root->left, tree);
        tree.push_back(root->data);
        inorder(root->right, tree);
    }

public:
    int countPairs(Node *root1, Node *root2, int x)
    {
        vector<int> tree1, tree2;
        int count = 0;

        inorder(root1, tree1);
        inorder(root2, tree2);

        int l = 0, r = tree2.size() - 1;

        while (l < tree1.size() && r >= 0)
        {
            if (tree1[l] + tree2[r] == x)
            {
                count++;
                l++;
                r--;
            }
            else if (tree1[l] + tree2[r] < x)
                l++;
            else
                r--;
        }
        return count;
    }
};
/*
Method 2:
TC-O(N) SC-O(N) :
*/