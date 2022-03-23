#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1/

Given a grid of size n*m (n is number of rows and m is number of columns grid has) consisting of '0's(Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
*/
/*
Method 1:
TC-O(N*M) SC-O(N*M) :
*/
class Solution
{
public:
    bool check(int i, int j, int &n, int &m)
    {
        if (i < 0 or i >= n or j < 0 or j >= m)
            return false;
        return true;
    }

    void numIslandsUtil(vector<vector<char>> &grid, int i, int j, int &n, int &m)
    {
        if (!check(i, j, n, m))
            return;

        int directions[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        if (grid[i][j] == '1')
        {
            grid[i][j] = '0';

            for (int k = 0; k < 8; k++)
            {
                numIslandsUtil(grid, i + directions[k][0], j + directions[k][1], n, m);
            }
        }
    }

    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0, n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    numIslandsUtil(grid, i, j, n, m);
                }
            }
        }

        return res;
    }
};