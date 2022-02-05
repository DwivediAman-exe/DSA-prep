#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1/

Given two Binary Search Trees. Find the nodes that are common in both of them, ie- find the intersection of the two BSTs.

Input:
BST1:
                  5
               /     \
             1        10
           /   \      /
          0     4    7
                      \
                       9
BST2:
                10
              /    \
             7     20
           /   \
          4     9
Output: 4 7 9 10
*/
/*
Method 1:
TC-O(M+N) SC-O(M+N) :
Create 2 vectors to store the inorder traversal of both the BSTs and find intersection of the two sorted arrays.

*/

/*
Method 2:
TC-O(M+N) SC-O(H1 + H2) :
*/
class Solution
{
public:
    // Function to find the nodes that are common in both BST.
    vector<int> findCommon(Node *root1, Node *root2)
    {
        stack<Node *> s1, s2;
        vector<int> res;
        Node *t1 = root1, *t2 = root2;
        while (t1 or t2 or (!s1.empty() && !s2.empty()))
        {
            while (t1)
            {
                s1.push(t1);
                t1 = t1->left;
            }
            while (t2)
            {
                s2.push(t2);
                t2 = t2->left;
            }
            if (!s1.empty() && !s2.empty())
            {
                if (s1.top()->data == s2.top()->data)
                {
                    res.push_back(s1.top()->data);
                    t1 = s1.top();
                    t2 = s2.top();
                    s1.pop();
                    s2.pop();
                    t1 = t1->right;
                    t2 = t2->right;
                }
                else if (s1.top()->data < s2.top()->data)
                {
                    t1 = s1.top();
                    s1.pop();
                    t1 = t1->right;
                    t2 = NULL;
                }
                else
                {
                    t2 = s2.top();
                    s2.pop();
                    t2 = t2->right;
                    t1 = NULL;
                }
            }
        }
        return res;
    }
};