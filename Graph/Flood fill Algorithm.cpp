#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1/

An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.
Output: {{2,2,2},{2,2,0},{2,0,1}}
*/
/*
Method 1:
TC-O(N * M) SC-O(1) :
*/
class Solution
{
public:
    bool isValid(int x, int y, int n, int m)
    {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {

        int n = image.size();
        int m = image[0].size();
        int color = image[sr][sc];

        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, 1, -1, 0};

        queue<pair<int, int>> q;
        q.push({sr, sc});

        image[sr][sc] = newColor;

        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int x = p.first + dx[i];
                int y = p.second + dy[i];

                if (isValid(x, y, n, m) && image[x][y] == color && image[x][y] != newColor) // important
                {
                    image[x][y] = newColor;
                    q.push({x, y});
                }
            }
        }

        return image;
    }
};