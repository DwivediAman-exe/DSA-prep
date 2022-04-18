#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/

The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stocks price for all n days.
The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Input:
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
*/

/*
Method 1:
TC-O(N) SC-O(N) :
*/

class Solution
{
public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        stack<pair<int, int>> st;
        vector<int> res;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top().first <= price[i])
                st.pop();

            if (st.empty())
                res.push_back(i + 1);
            else
                res.push_back(i - st.top().second);

            st.push({price[i], i});
        }

        return res;
    }
};