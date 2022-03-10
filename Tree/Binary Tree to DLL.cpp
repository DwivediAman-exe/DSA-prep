#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1/

Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

Input:
      1
    /  \
   3    2
Output:
3 1 2
2 1 3
*/
/*
Method 1:

TC-O(N) SC-O(H) :
*/
class Solution
{
public:
    void bToDLLUtil(Node *root, Node *&prev, Node *&head)
    {
        if (!root)
            return;

        bToDLLUtil(root->left, prev, head);

        if (!prev)
            head = root;
        else
        {
            root->left = prev;
            prev->right = root;
        }
        prev = root;

        bToDLLUtil(root->right, prev, head);
    }
    // Function to convert binary tree to doubly linked list and return it.
    Node *bToDLL(Node *root)
    {
        Node *prev = NULL, *head = NULL;

        bToDLLUtil(root, prev, head);

        return head;
    }
};