#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1/

Given a Binary Search Tree and a target sum. Check whether there's a pair of Nodes in the BST with value summing up to the target sum.

Input:
        2
      /   \
     1     3
sum = 5
Output: 1

Method 1:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    // root : the root Node of the given BST
    // target : the target sum
    bool helper(Node *r, int target, unordered_set<int> &s)
    {
        if (r == NULL)
            return false;
        if (s.find(target - r->data) != s.end())
            return true;

        if (helper(r->left, target, s) == true)
            return true;

        s.insert(r->data);

        if (helper(r->right, target, s) == true)
            return true;
    }
    int isPairPresent(struct Node *root, int target)
    {
        unordered_set<int> s;
        return helper(root, target, s);
    }
};
/*
Method 2:
TC-O(N) SC-O(H) :
*/
class Solution
{
public:
    // root : the root Node of the given BST
    // target : the target sum

    int isPairPresent(struct Node *root, int target)
    {
        Node *curr1 = root;
        Node *curr2 = root;

        stack<Node *> s1; // for normal inorder.
        stack<Node *> s2; // for reverse inorder.

        bool got_next_inorder = false, got_reverse_inorder = false;

        int val1, val2;

        while (true)
        {
            while (!got_next_inorder)
            {
                if (curr1 != NULL)
                {
                    s1.push(curr1);
                    curr1 = curr1->left;
                }
                else
                {
                    if (s1.empty())
                    {
                        got_next_inorder = true;
                    }
                    else
                    {
                        curr1 = s1.top();
                        s1.pop();
                        val1 = curr1->data;
                        curr1 = curr1->right;
                        got_next_inorder = true;
                    }
                }
            }

            while (!got_reverse_inorder)
            {
                if (curr2 != NULL)
                {
                    s2.push(curr2);
                    curr2 = curr2->right;
                }
                else
                {
                    if (s2.empty())
                    {
                        got_reverse_inorder = true;
                    }
                    else
                    {
                        curr2 = s2.top();
                        s2.pop();
                        val2 = curr2->data;
                        curr2 = curr2->left;
                        got_reverse_inorder = true;
                    }
                }
            }

            if (val1 < val2)
            {
                if (val1 + val2 == target)
                    return 1;
                else if (val1 + val2 < target)
                    got_next_inorder = false;
                else if (val1 + val2 > target)
                    got_reverse_inorder = false;
            }
            else
            {
                return 0;
            }
        }
    }
};