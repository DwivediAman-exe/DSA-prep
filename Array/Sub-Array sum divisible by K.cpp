#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/sub-array-sum-divisible-by-k2617/1/

You are given an array A of N positive and/or negative integers and a value K. The task is to find the count of all sub-arrays whose sum is divisible by K.

Input: N = 6, K = 5
       arr[] = {4, 5, 0, -2, -3, 1}
Output: 7

Method 1:
TC-O(N) SC-O(1) :
*/
class Solution
{

public:
    long long subCount(long long arr[], int N, long long K)
    {
        long long sum[K] = {0};
        long long s = 0, ans = 0;

        for (int i = 0; i < N; i++)
        {
            s += arr[i];
            long long rem = (s % K);
            if (rem < 0)
                rem += K;
            ans += sum[rem];
            sum[rem]++;
        }

        ans += sum[0];

        return ans;
    }
};
/*
Let there be a subarray (i, j) whose sum is divisible by k
  sum(i, j) = sum(0, j) - sum(0, i-1)
Sum for any subarray can be written as q*k + rem where q
is a quotient and rem is remainder
Thus,
    sum(i, j) = (q1 * k + rem1) - (q2 * k + rem2)
    sum(i, j) = (q1 - q2)k + rem1-rem2

We see, for sum(i, j) i.e. for sum of any subarray to be
divisible by k, the RHS should also be divisible by k.
(q1 - q2)k is obviously divisible by k, for (rem1-rem2) to
follow the same, rem1 = rem2 where
    rem1 = Sum of subarray (0, j) % k
    rem2 = Sum of subarray (0, i-1) % k
*/