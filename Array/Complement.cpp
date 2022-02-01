#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/complement3911/1/

You are given a binary string str. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and complement the characters between L and R i.e strL, strL+1, …, strR. By complement, we mean change character 0 to 1 and vice-versa.

You task is to perform ATMOST one operation such that in final string number of 1s is maximised. If there is no need to completement, i.e., string contains all 1s, return -1. Else, return the two values denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

Input:
    N = 2
    str = "01"
Output: 1 1

Method 1:
TC-O(N) SC-O(1) :
*/
class Solution
{
public:
    vector<int> findRange(string str, int n)
    {
        int l = -1, r = -1, s = 0, mx_sum = 0, curr = 0;

        for (int i = 0; i < n; i++)
        {
            int x = (str[i] == '0') ? 1 : -1;
            if (curr + x < x)
            {
                s = i;
                curr = x;
            }
            else
                curr += x;

            if (curr > mx_sum)
            {
                l = s;
                r = i;
                mx_sum = curr;
            }
        }

        if (l == r && l == -1)
            return {-1};
        else
            return {l + 1, r + 1};
    }
};