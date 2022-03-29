#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem4816/1/

Given a 5x6 snakes and ladders board, find the minimum number of dice throws required to reach the destination or last cell (30th cell) from the source (1st cell).

You are given an integer N denoting the total number of snakes and ladders and an array arr[] of 2*N size where 2*i and (2*i + 1)th values denote the starting and ending point respectively of ith snake or ladder.

Input:
N = 8
arr[] = {3, 22, 5, 8, 11, 26, 20, 29,
       17, 4, 19, 7, 27, 1, 21, 9}
Output: 3
*/
/*
Method 1:
TC-O(N) SC-O(N) : BFS
*/
class Solution
{
public:
    int minThrow(int N, int arr[])
    {
        unordered_map<int, int> mp;
        vector<bool> vis(30, false);

        for (int i = 0; i < 2 * N; i += 2)
        {
            mp[arr[i]] = arr[i + 1];
        }

        queue<pair<int, int>> q;

        q.push({1, 0});
        vis[0] = true;

        while (!q.empty())
        {
            pair<int, int> ele = q.front();
            q.pop();

            int pos = ele.first;
            int moves = ele.second;

            if (pos == 30)
                return moves;

            for (int k = 1; k <= 6; k++)
            {
                int newPos = pos + k;

                if (!vis[newPos - 1] && newPos <= 30)
                {
                    vis[newPos - 1] = true;
                    if (mp.find(newPos) == mp.end())
                    {
                        q.push({newPos, moves + 1});
                    }
                    else
                    {
                        q.push({mp[newPos], moves + 1});
                    }
                }
            }
        }

        return -1;
    }
};