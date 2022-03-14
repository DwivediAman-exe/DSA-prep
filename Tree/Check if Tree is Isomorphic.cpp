#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1/

Given two Binary Trees. Check whether they are Isomorphic or not.

Note:
Two trees are called isomorphic if one can be obtained from another by a series of flips, i.e. by swapping left and right children of several nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.
For example, the following two trees are isomorphic with the following sub-trees flipped: 2 and 3, NULL and 6, 7 and 8.

Input:
 T1    1     T2:   1
     /   \        /  \
    2     3      3    2
   /            /
  4            4
Output: No
*/
/*
Method 1:
TC-O(min(M,N)) SC-O(min(H1,H2)) :
*/
class Solution
{
public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1, Node *root2)
    {
        if (!root1 && !root2)
            return true;
        if ((root1 && !root2) || (root2 && !root1) || (root1->data != root2->data))
            return false;

        return (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left)) or (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right));
    }
};