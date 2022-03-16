#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1/

Given a binary tree and an integer X. Your task is to complete the function countSubtreesWithSumX() that returns the count of the number of subtress having total node’s data sum equal to the value X.

Input:
       5
    /    \
  -10     3
 /   \   /  \
 9   8 -4    7
X = 7
Output: 2
*/
/*
Method 1:
TC-O(N^2) SC-O(H) :
For each node find sum of left subtree, rightsubtree and check with given sum.
*/

/*
Method 2:
TC-O(N) SC-O(H) :
*/
int countSubtreesWithSumXUtil(Node *root, int X, int &count)
{
    if (!root)
        return 0;

    int ls = countSubtreesWithSumXUtil(root->left, X, count);
    int rs = countSubtreesWithSumXUtil(root->right, X, count);

    int sum = ls + rs + root->data;

    if (sum == X)
        count++;

    return sum;
}
// Function to count number of subtrees having sum equal to given sum.
int countSubtreesWithSumX(Node *root, int X)
{
    int count = 0;

    countSubtreesWithSumXUtil(root, X, count);

    return count;
}