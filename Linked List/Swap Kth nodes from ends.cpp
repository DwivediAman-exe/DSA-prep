#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/swap-kth-node-from-beginning-and-kth-node-from-end-in-a-singly-linked-list/1#

Given a singly linked list of size N, and an integer K. You need to swap the Kth node from the beginning and Kth node from the end of the linked list. Swap the nodes through the links. Do not change the content of the nodes.

Input:
N = 4,  K = 1
value[] = {1,2,3,4}
Output: 1
Explanation: Here K = 1, hence after swapping the 1st node from the beginning and end the new list will be 4 2 3 1.
*/
/*
Method 1:
TC-O(N) SC-O(1) :
*/
Node *swapkthnode(Node *head, int num, int K)
{
    if ((num < K) || (2 * K - 1 == num))
        return head;

    Node *x = head, *x_prev = NULL, *y = head, *y_prev = NULL, *temp = NULL;

    int i = 1;

    while (i < K)
    {
        x_prev = x;
        x = x->next;
        i++;
    }

    i = 1;

    while (i < num - K + 1)
    {
        y_prev = y;
        y = y->next;
        i++;
    }

    if (x_prev)
        x_prev->next = y;

    if (y_prev)
        y_prev->next = x;

    temp = x->next;
    x->next = y->next;
    y->next = temp;

    if (K == 1)
        head = y;
    else if (K == num)
        head = x;

    return head;
}