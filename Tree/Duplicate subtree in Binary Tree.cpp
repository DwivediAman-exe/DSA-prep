#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1/

Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.

Input :
               1
             /   \
           2       3
         /   \       \
        4     5       2
                     /  \
                    4    5
Output : 1
*/
/*
Method 1:
TC-O(N^2) SC-O(N) :
A simple solution is that, we pick every node of tree and try to find is any sub-tree of given tree is present in tree which is identical with that sub-tree. Here we can use below post to find if a subtree is present anywhere else in tree.
*/

/*
Method 2:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    string dupSubUtil(Node *root, unordered_set<string> &st, bool &ans)
    {
        if (!root)
            return "";

        string t = "";

        t += root->data;
        t += dupSubUtil(root->left, st, ans) + dupSubUtil(root->right, st, ans);

        if (st.find(t) == st.end())
        {
            if (root->left || root->right)
                st.insert(t);
        }
        else
            ans = true;

        return t;
    }
    /*This function returns true if the tree contains
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root)
    {
        bool ans = false;
        unordered_set<string> st;
        dupSubUtil(root, st, ans);
        return ans;
    }
};