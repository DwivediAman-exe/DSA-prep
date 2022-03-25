#include <bits/stdc++.h>
using namespace std;
/*
Question Link -

Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.

Input: grid = {{3,0,3,0,0},{3,0,0,0,3}
,{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
Output: 0
*/
/*
Method 1:
TC-O(N^2) SC-O(N^2) :
*/
class Solution
{
public:
    bool isValid(int i, int j, int N, vector<vector<int>> &grid)
    {
        return i >= 0 && i < N && j >= 0 && j < N && (grid[i][j] != 0);
    }
    // Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>> &grid)
    {
        int n = grid.size();

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    break;
                }
            }
        }

        while (!q.empty())
        {
            pair<int, int> temp = q.front();
            q.pop();

            int i = temp.first, j = temp.second;

            if (grid[i][j] == 2)
                return 1;

            if (!vis[i][j])
            {
                vis[i][j] = true;

                for (int k = 0; k < 4; k++)
                {
                    int x = i + dir[k].first;
                    int y = j + dir[k].second;

                    if (isValid(x, y, n, grid) && !vis[x][y])
                    {
                        q.push({x, y});
                    }
                }
            }
        }

        return 0;
    }
};