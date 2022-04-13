#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/median-of-bst/1

Given a Binary Search Tree of size N, find the Median of its Node values.

Input:
       6
     /   \
   3      8
 /  \    /  \
1    4  7    9
Output: 6
*/
/*
Method 1:
TC-O(N) SC-O(N) :
*/
void inorder(struct Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    inorderr(root->left, v);
    v.push_back(root->data);
    inorderr(root->right, v);
}
float findMedian(struct Node *root)
{

    vector<int> v;
    inorder(root, v);
    if (v.size() % 2 == 0)
    {
        return (float)(v[v.size() / 2] + v[(v.size() / 2) - 1]) / 2;
    }
    else
    {
        return v[v.size() / 2];
    }
}

/*
Method 2:
TC-O(N) SC-O(H) :
*/
void count_nodes(Node *root, int &t)
{
    if (!root)
        return;
    count_nodes(root->left, t);
    t++;
    count_nodes(root->right, t);
}

void findMedianUtil(Node *root, Node *&cur, Node *&prev, int &c, int k)
{
    if (!root)
        return;

    findMedianUtil(root->left, cur, prev, c, k);
    // cout<<c<<' '<<root->data<<'\n';
    if (prev == NULL)
    {
        prev = root;
        c++;
    }
    else if (c == k)
    {
        cur = root;
        c++;
        return;
    }
    else
    {
        c++;
        if (c <= k)
            prev = root;
    }
    findMedianUtil(root->right, cur, prev, c, k);
}

float findMedian(struct Node *root)
{
    int n = 0;
    count_nodes(root, n);

    Node *cur = NULL;
    Node *prev = NULL;

    int c = 1;
    int x = (n / 2) + 1;

    findMedianUtil(root, cur, prev, c, x);

    if (n % 2 != 0)
    {
        float ans = (cur->data) * 1.0;
        return ans;
    }
    else
    {
        float ans = ((cur->data + prev->data) * 1.0) / (2 * 1.0);
        return ans;
    }
}

/*
Method 2:
TC-O(N) SC-O(1) : Morris Traversal
*/
int count(Node *root)
{
    if (!root)
        return 0;

    int c = 0;

    Node *curr = root;

    while (curr)
    {
        if (!curr->left)
        {
            c++;
            curr = curr->right;
        }
        else
        {
            Node *pred = curr->left;

            while (pred->right && pred->right != curr)
                pred = pred->right;

            if (pred->right == curr)
            {
                pred->right = NULL;
                c++;
                curr = curr->right;
            }
            else
            {
                pred->right = curr;
                curr = curr->left;
            }
        }
    }
    return c;
}
float findMedian(struct Node *root)
{
    int c = count(root), currCount = 0;

    Node *curr = root, *prev = NULL;

    while (curr)
    {
        if (!curr->left)
        {
            currCount++;
            if ((c % 2 == 0) && (currCount == c / 2 + 1))
                return ((float)curr->data + prev->data) / 2.0;
            if ((c % 2 == 1) && (currCount == (c + 1) / 2))
                return curr->data;
            prev = curr;
            curr = curr->right;
        }
        else
        {
            Node *pred = curr->left;

            while (pred->right && pred->right != curr)
                pred = pred->right;

            if (pred->right == curr)
            {
                currCount++;
                if ((c % 2 == 0) && (currCount == c / 2 + 1))
                    return ((float)curr->data + prev->data) / 2.0;
                if ((c % 2 == 1) && (currCount == (c + 1) / 2))
                    return curr->data;
                pred->right = NULL;
                prev = curr;

                curr = curr->right;
            }
            else
            {
                pred->right = curr;

                curr = curr->left;
            }
        }
    }
}