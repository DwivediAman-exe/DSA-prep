#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1/

Given a binary tree of size N, your task is to that find all duplicate subtrees from the given binary tree.

*/
/*
Method 1:
TC-O(N^2) SC-O(N^2) :
*/
string printAllDupsUtil(Node *root, vector<Node *> &res, map<string, int> &mp)
{
    if (!root)
        return "$";

    string s = to_string(root->data);

    s += '$' + printAllDupsUtil(root->left, res, mp);
    s += '$' + printAllDupsUtil(root->right, res, mp);

    if (mp.find(s) == mp.end())
        mp[s] = 0;
    else
    {
        if (mp[s] == 0)
            res.push_back(root);

        mp[s]++;
    }

    return s;
}

// you are required to complete this function
// the function and return an vector of Node
// which contains all the duplicate sub-tree
vector<Node *> printAllDups(Node *root)
{
    map<string, int> mp;
    vector<Node *> res;

    printAllDupsUtil(root, res, mp);

    return res;
}
