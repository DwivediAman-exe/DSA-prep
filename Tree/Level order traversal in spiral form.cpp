#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1/

Complete the function to find spiral order traversal of a tree. For below tree, function should return 1, 2, 3, 4, 5, 6, 7.

Input:
      1
    /   \
   3     2
Output:1 3 2
*/
/*
Method 1:
TC-O(N^2) SC-O(H) :
Calculate height of the tree. Iterate from 1 to H. Print each level.
*/

/*
Method 2:
TC-O(N) SC-O(N) :
*/
// Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    vector<int> res;
    if (!root)
        return res;
    bool reverse = false;

    stack<Node *> s1, s2;

    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        if (!reverse)
        {
            while (!s1.empty())
            {
                Node *temp = s1.top();
                s1.pop();
                res.push_back(temp->data);

                if (temp->right)
                    s2.push(temp->right);

                if (temp->left)
                    s2.push(temp->left);
            }
        }
        else
        {
            while (!s2.empty())
            {
                Node *temp = s2.top();
                s2.pop();
                res.push_back(temp->data);

                if (temp->left)
                    s1.push(temp->left);

                if (temp->right)
                    s1.push(temp->right);
            }
        }
        reverse = !reverse;
    }

    return res;
}