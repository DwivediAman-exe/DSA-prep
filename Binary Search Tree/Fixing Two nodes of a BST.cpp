#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1/

You are given the root of a binary search tree(BST), where exactly two nodes were swapped by mistake. Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be reflected in the original linked list.

Input:
       10
     /    \
    5      8
   / \
  2   20
Output: 1

Method 1:
TC-O(N) SC-O(N) :
Take the inorder traversal of the BST. It should be in sorted order. Correct the 2 nodes that dont follow this condition.
*/

/*
Method 2:
TC-O(N) SC-O(H) :
*/
class Solution
{
public:
    void swap(Node *a, Node *b)
    {
        int t = a->data;
        a->data = b->data;
        b->data = t;
    }

    void correctBSTUtil(Node *root, Node **p, Node **first, Node **second, Node **third)
    {
        if (root == NULL)
            return;

        correctBSTUtil(root->left, p, first, second, third);

        if (*p && (*p)->data > root->data)
        {

            if (*first == NULL)
            {
                *first = *p;
                *second = root;
            }
            else
            {
                *third = root;
            }
        }

        *p = root;

        correctBSTUtil(root->right, p, first, second, third);
    }

    void correctBST(struct Node *root)
    {
        Node *p = NULL, *first = NULL, *second = NULL, *third = NULL;

        correctBSTUtil(root, &p, &first, &second, &third);

        if (first && third)
        {
            swap(first, third);
        }
        else if (first && second)
        {
            swap(first, second);
        }
    }
};
/*
We will maintain three pointers, first, middle and last. When we find the first point where current node value is smaller than previous node value, we update the first with the previous node & middle with the current node. When we find the second point where current node value is smaller than previous node value, we update the last with the current node. In case #2, we will never find the second point. So, last pointer will not be updated. After processing, if the last node value is null, then two swapped nodes of BST are adjacent.
*/