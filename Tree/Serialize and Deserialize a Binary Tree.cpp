#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1/

Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. Now your task is to complete the function serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to the tree and returns it.
Note: The structure of the tree must be maintained. Multiple nodes can have the same data.

Input:
      1
    /   \
   2     3
Output: 2 1 3
*/
/*
Method 1:

TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    void serializeUtil(Node *root, vector<int> &res)
    {
        if (!root)
        {
            res.push_back(-1);
            return;
        }
        res.push_back(root->data);
        serializeUtil(root->left, res);
        serializeUtil(root->right, res);
    }
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        vector<int> res;
        serializeUtil(root, res);
        return res;
    }

    Node *deSerializeUtil(vector<int> &A, int &i)
    {
        if (i == A.size())
        {
            return NULL;
        }
        if (A[i] == -1)
            return NULL;

        Node *root = new Node(A[i++]);

        root->left = deSerializeUtil(A, i);
        root->right = deSerializeUtil(A, ++i);

        return root;
    }
    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &A)
    {
        int i = 0;
        return deSerializeUtil(A, i);
    }
};