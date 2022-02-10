#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/sorted-list-to-bst/1/

Given a Singly Linked List which has data members sorted in ascending order. Construct a Balanced Binary Search Tree which has same data members as the given Linked List.
Note: There might be nodes with same value.

Input:
Linked List: 1->2->3->4->5->6->7
Output:
4 2 1 3 6 5 7

Method 1:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    LNode *getMidNode(LNode *head)
    {
        LNode *fast = head, *slow = head, *prev = NULL;

        while (fast and fast->next)
        {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = NULL;

        return slow;
    }

    TNode *sortedListToBST(LNode *head)
    {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return new TNode(head->data);

        LNode *mid = getMidNode(head);
        TNode *root = new TNode(mid->data);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
};