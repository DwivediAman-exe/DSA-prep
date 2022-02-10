#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/bst-to-max-heap/1/

Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Max Heap.

Input :
                 4
               /   \
              2     6
            /  \   /  \
           1   3  5    7

Output : 1 2 3 4 5 6 7
*/
/*
Method 1:

TC-O(N) SC-O(N) :
*/

class Solution
{
public:
    void convertToMaxHeap(Node *root, vector<int> &v, int &i)
    {
        if (!root)
            return;

        convertToMaxHeap(root->left, v, i);
        convertToMaxHeap(root->right, v, i);

        root->data = v[i++];
    }

    void inorder(Node *root, vector<int> &v)
    {
        if (!root)
            return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    void convertToMaxHeapUtil(Node *root)
    {
        int i = 0;
        vector<int> v;
        inorder(root, v);
        convertToMaxHeap(root, v, i);
    }
};