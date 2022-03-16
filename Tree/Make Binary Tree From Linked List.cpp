#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/make-binary-tree/1/

Given a Linked List Representation of Complete Binary Tree. The task is to construct the Binary tree.
Note : The complete binary tree is represented as a linked list in a way where if root node is stored at position i, its left, and right children are stored at position 2*i+1, 2*i+2 respectively.

Input:
N = 5
K = 1->2->3->4->5
Output: 1 2 3 4 5
*/
/*
Method 1:

TC-O(N) SC-O(N) :
*/
// Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root)
{
    queue<TreeNode *> q;

    root = new TreeNode(head->data);
    head = head->next;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        if (head)
        {
            temp->left = new TreeNode(head->data);
            q.push(temp->left);
            head = head->next;
        }

        if (head)
        {
            temp->right = new TreeNode(head->data);
            q.push(temp->right);
            head = head->next;
        }
    }
}