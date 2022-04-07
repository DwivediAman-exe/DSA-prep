#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1/

Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer.

Input: A = "aabc"
Output: "a#bb"
*/
/*
Method 1:
TC-O(N*26) SC-O(26) :
*/
class Node
{
public:
    Node *prev, *next;
    int data;
    Node(int d)
    {
        data = d;
        prev = next = NULL;
    }
};

void append(Node *newnode, Node **head, Node **tail)
{

    if (*head == NULL)
    {
        *head = *tail = newnode;
        return;
    }

    (*tail)->next = newnode;
    newnode->prev = *tail;
    *tail = newnode;
}

void deleteNode(Node *node, Node **head, Node **tail)
{
    if (*head == NULL)
        return;

    if (*head == node)
    {
        *head = (*head)->next;
    }
    if (*tail == node)
    {
        *tail = (*tail)->prev;
    }
    if (node->next)
    {
        node->next->prev = node->prev;
    }
    if (node->prev)
    {
        node->prev->next = node->next;
    }

    delete (node);
}

class Solution
{
public:
    string FirstNonRepeating(string A)
    {

        string res;

        bool rep[26] = {false};
        vector<Node *> inDLL(26, NULL);
        Node *head = NULL, *tail = NULL;

        for (int i = 0; i < A.length(); i++)
        {
            int x = A[i] - 'a';

            if (!rep[x])
            {
                if (inDLL[x])
                {
                    rep[x] = true;
                    deleteNode(inDLL[x], &head, &tail);
                    inDLL[x] = false;
                }
                else
                {
                    inDLL[x] = new Node(x);
                    append(inDLL[x], &head, &tail);
                }
            }

            if (head == NULL)
                res += '#';
            else
            {
                res += head->data + 'a';
            }
        }

        return res;
    }
};