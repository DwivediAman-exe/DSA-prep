#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/check-if-subtree/1/

Given two binary trees with head reference as T and S having at most N nodes. The task is to check if S is present as subtree in T.
A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.

Input:
T:      1          S:   3
      /   \            /
     2     3          4
   /  \    /
  N    N  4
Output: 1
*/
/*
Method 1:
TC-O(N*M) SC-O(H) :
*/
class Solution
{
public:
    bool isSubTreeUtil(Node *T, Node *S)
    {
        if (!T && !S)
            return true;
        else if ((!T && S) || (T && !S))
            return false;

        if (T->data != S->data)
            return false;

        return isSubTreeUtil(T->left, S->left) && isSubTreeUtil(T->right, S->right);
    }
    // Function to check if S is a subtree of tree T.
    bool isSubTree(Node *T, Node *S)
    {
        if (!T)
            return false;

        if (T->data == S->data && isSubTreeUtil(T, S))
        {
            return true;
        }
        else
        {
            return isSubTree(T->left, S) || isSubTree(T->right, S);
        }
    }
};
/*
Method 2:
TC-O(N) SC-O(N) :
*/

class Solution
{
public:
    void storeInorder(Node *root, string &res)
    {
        if (root == NULL)
        {
            res += '#';
            return;
        }
        storeInorder(root->left, res);
        res += to_string(root->data);
        storeInorder(root->right, res);
    }

    void storePreOrder(Node *root, string &res)
    {
        if (root == NULL)
        {
            res += '#';
            return;
        }
        res += to_string(root->data);
        storePreOrder(root->left, res);
        storePreOrder(root->right, res);
    }
    // Function to check if S is a subtree of tree T.
    bool isSubTree(Node *T, Node *S)
    {
        if (S == NULL)
            return true;
        if (T == NULL)
            return false;

        string in1 = "", pre1 = "", in2 = "", pre2 = "";

        storeInorder(T, in1);
        storeInorder(S, in2);

        if (in1.find(in2) == string::npos)
            return false;

        storePreOrder(T, pre1);
        storePreOrder(S, pre2);

        if (pre1.find(pre2) == string::npos)
            return false;

        return true;
    }
};