#include <bits/stdc++.h>
using namespace std;
/*
Question Link -

Given the binary Tree of and two-node values. Check whether the two-node values are cousins of each other or not.

Input:
      1
    /   \
   2     3
a = 2, b = 3
Output: 0
*/
/*
Method 1:
TC-O(N) SC-O(N) : (3 traversal)
The idea is to find level of one of the nodes. Using the found level, check if ‘a’ and ‘b’ are at this level. If ‘a’ and ‘b’ are at given level, then finally check if they are not children of same parent.
*/

/*
Method 2:
TC-O(N) SC-O(N) :
*/
bool isCousins(Node *root, int a, int b)
{
    queue<pair<Node *, Node *>> q;
    q.push({root, NULL});

    Node *parA = NULL, *parB = NULL;

    while (!q.empty())
    {
        int n = q.size();

        while (n--)
        {
            Node *temp = q.front().first;
            if (temp->data == a)
            {
                parA = q.front().second;
            }
            if (temp->data == b)
            {
                parB = q.front().second;
            }
            q.pop();

            if (temp->left)
                q.push({temp->left, temp});

            if (temp->right)
                q.push({temp->right, temp});
        }

        if (parA && parB)
        {
            return parA != parB;
        }
        else if (parA || parB)
            return false;
    }
}