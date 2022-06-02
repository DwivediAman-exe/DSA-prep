#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://leetcode.com/problems/remove-linked-list-elements/

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
*/
/*
Method 1:
TC-O(N) SC-O(1) :
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {

        if (!head)
            return head;

        while (head and head->val == val)
            head = head->next;

        if (!head)
            return head;

        ListNode *prev = head, *curr = head->next;

        while (curr)
        {
            if (curr->val == val)
                prev->next = curr->next;
            else
                prev = curr;
            curr = curr->next;
        }

        return head;
    }
};