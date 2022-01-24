#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1

The cost of stock on each day is given in an array A[] of size N.
Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.
Note: There may be multiple possible solutions. Return any one of them.
Any correct solution will result in an output of 1, whereas wrong solutions will result in an output of 0.
Input:
N = 7
A[] = {100,180,260,310,40,535,695}
Output:
1
Explanation: We can buy stock on day 0,and sell it on 3rd day, which will give us maximum profit. Now, we buy stock on day 4 and sell it on day 6.

Method 1:
TC - O(N) SC - O(N)
*/
class Solution
{
public:
    vector<vector<int>> stockBuySell(vector<int> arr, int n)
    {
        vector<vector<int>> ans;
        vector<int> v;

        int flag = 1; // v is empty
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                if (flag == 1)
                {
                    v.push_back(i - 1);
                    flag = 0;
                }
                if (i == n - 1)
                {
                    v.push_back(i);
                    ans.push_back(v);
                }
            }
            else
            {
                if (flag != 1)
                {
                    v.push_back(i - 1);
                    ans.push_back(v);
                    v.clear();
                    flag = 1;
                }
            }
        }
        return ans;
    }
};
