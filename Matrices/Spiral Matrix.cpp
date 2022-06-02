#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://leetcode.com/problems/spiral-matrix/

Given an m x n matrix, return all elements of the matrix in spiral order.
*/
/*
Method 1:
TC-O(M*N) SC-O(1) :
*/

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;

        int rowBegin = 0, rowEnd = matrix.size() - 1, colBegin = 0, colEnd = matrix[0].size() - 1;
        while (rowBegin <= rowEnd and colBegin <= colEnd)
        {
            // Move right

            for (int i = colBegin; i <= colEnd; i++)
            {
                res.push_back(matrix[rowBegin][i]);
            }

            rowBegin++;

            // Move down

            for (int i = rowBegin; i <= rowEnd; i++)
            {
                res.push_back(matrix[i][colEnd]);
            }

            colEnd--;

            // Move left
            if (rowBegin <= rowEnd)
            {
                for (int i = colEnd; i >= colBegin; i--)
                {
                    res.push_back(matrix[rowEnd][i]);
                }
            }

            rowEnd--;

            // Move up
            if (colBegin <= colEnd)
            {
                for (int i = rowEnd; i >= rowBegin; i--)
                {
                    res.push_back(matrix[i][colBegin]);
                }
            }
            colBegin++;
        }

        return res;
    }
};