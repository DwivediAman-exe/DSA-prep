#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/binary-tree-to-cdll/1/

Given a Binary Tree of N edges. The task is to convert this to a Circular Doubly Linked List(CDLL) in-place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted CDLL. The order of nodes in CDLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must be head node of the CDLL.

Input:
      1
    /   \
   3     2
Output:
3 1 2
2 1 3
*/
/*
Method 1:

TC-O(N) SC-O(N) :
*/

class Solution
{
public:
    void bTreeToCListUtil(Node *root, Node *&prev, Node *&head)
    {
        if (!root)
            return;

        bTreeToCListUtil(root->left, prev, head);

        if (prev != NULL)
        {
            prev->right = root;
            root->left = prev;
        }
        else
            head = root;

        prev = root;

        bTreeToCListUtil(root->right, prev, head);
    }

    // Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root)
    {
        Node *prev = NULL, *head = NULL;

        bTreeToCListUtil(root, prev, head);

        prev->right = head;
        head->left = prev;

        return head;
    }
};