#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1/

The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).

Input:
       1
     /  \
    2    3
Output: 3
*/
/*
Method 1:
TC-O(N) SC-O(H) :
*/
class Solution
{
public:
    int diameterUtil(Node *root, int &ans)
    {
        if (!root)
            return 0;

        int l = diameterUtil(root->left, ans);
        int r = diameterUtil(root->right, ans);

        ans = max(ans, l + r + 1);

        return max(l, r) + 1;
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node *root)
    {
        int ans = INT_MIN;

        diameterUtil(root, ans);

        return ans;
    }
};