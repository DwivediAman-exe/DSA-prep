#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1/

Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j).

Note: It is assumed that negative cost cycles do not exist in the input matrix.

Input: grid = {{9,4,9,9},{6,7,6,4},
{8,3,3,7},{7,4,9,10}}
Output: 43
*/
/*
Method 1:
TC-O(N^2* log(N)) SC-O(N^2) :
*/
class Solution
{
public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    bool isSafe(int x, int y, int n)
    {
        if (x < 0 || y < 0 || x >= n || y >= n)
            return false;
        return true;
    }

    int minimumCostPath(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> d(n, vector<int>(n, INT_MAX));

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        d[0][0] = grid[0][0];

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({d[0][0], {0, 0}});

        while (!q.empty())
        {
            pair<int, pair<int, int>> temp = q.top();
            q.pop();

            int x = temp.second.first;
            int y = temp.second.second;

            int t = temp.first;
            for (int i = 0; i < 4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if (isSafe(newx, newy, n) && t + grid[newx][newy] < d[newx][newy])
                {
                    d[newx][newy] = t + grid[newx][newy];
                    q.push({d[newx][newy], {newx, newy}});
                }
            }
        }
        return d[n - 1][n - 1];
    }
};