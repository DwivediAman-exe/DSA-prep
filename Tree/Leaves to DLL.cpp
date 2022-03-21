#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/leaves-to-dll/1/

Given a Binary Tree of size N, extract all its leaf nodes to form a Doubly Link List starting from the left most leaf. Modify the original tree to make the DLL thus removing the leaf nodes from the tree. Consider the left and right pointers of the tree to be the previous and next pointer of the DLL respectively.

Input :
        1
      /   \
     2     3
    / \   / \
   4   5 6   7

Output:
Modified Tree :
        1
      /   \
     2     3

Doubly Link List :
4 <-> 5 <-> 6 <-> 7
*/
/*
Method 1:
TC-O(N) SC-O(N) : BFS
*/
// return the head of the DLL and remove those node from the tree as well.
Node *convertToDLL(Node *root)
{
    // add code here.
    queue<Node *> q;
    Node *dll = NULL, *dh = NULL;
    q.push(root);
    while (!q.empty())
    {
        Node *t = q.front();
        q.pop();
        if (!t->left && !t->right)
        {
            if (dll == NULL)
            {
                dll = t;
                dh = dll;
            }
            else
            {
                dll->left = t;
                t->right = dll;
                dll = t;
            }
        }
        else
        {
            Node *tl = NULL, *tr = NULL;

            if (t->right)
            {
                tr = t->right;
                if (!tr->left && !tr->right)
                {
                    t->right = NULL;
                }
                q.push(tr);
            }
            if (t->left)
            {
                tl = t->left;
                if (!tl->left && !tl->right)
                {
                    t->left = NULL;
                }
                q.push(tl);
            }
        }
    }
    return dll;
}

/*
Method 2:
TC-O(N) SC-O(N) : DFS
*/

Node *convertToDLLUtil(Node *root, Node *&prev, Node *&head)
{
    if (!root)
        return NULL;

    if (!root->left && !root->right)
    {
        if (head == NULL)
        {
            head = root;
        }
        else
        {
            prev->right = root;
            root->left = prev;
        }
        prev = root;
        return NULL;
    }

    root->left = convertToDLLUtil(root->left, prev, head);
    root->right = convertToDLLUtil(root->right, prev, head);

    return root;
}

// return the head of the DLL and remove those node from the tree as well.
Node *convertToDLL(Node *root)
{
    Node *head = NULL, *prev = NULL;
    root = convertToDLLUtil(root, prev, head);
    return head;
}