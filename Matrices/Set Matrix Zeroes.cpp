#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://leetcode.com/problems/set-matrix-zeroes/

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
*/
/*
Method 1:
TC-O(N * M) SC-O(M + N) :
*/
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int R = matrix.size();
        int C = matrix[0].size();
        unordered_set<int> rows, cols;

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (rows.find(i) != rows.end() || cols.find(j) != cols.end())
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
/*
Method 2:
TC-O(M * N) SC-O(1) :
*/
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        bool firstcolzero = false;

        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0)
                firstcolzero = true;

            for (int j = 1; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[i].size(); j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                matrix[0][j] = 0;
            }
        }

        if (firstcolzero)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};