#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1/

There is BST given with root node with key part as integer only. You need to find the inorder successor and predecessor of a given key. In case, if the either of predecessor or successor is not found print -1.

Input:
2
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
65
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
100

Output:
60 70
80 -1
*/
/*
Method 1:
TC-O(H) SC-O(H) :
*/
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{

    while (root)
    {
        if (root->key > key)
        {
            suc = root;
            root = root->left;
        }
        else if (root->key < key)
        {
            pre = root;
            root = root->right;
        }
        else
        {
            if (root->left)
            {
                Node *t = root->left;
                while (t->right)
                    t = t->right;
                pre = t;
            }
            if (root->right)
            {
                Node *t = root->right;
                while (t->left)
                    t = t->left;
                suc = t;
            }
            return;
        }
    }
}
