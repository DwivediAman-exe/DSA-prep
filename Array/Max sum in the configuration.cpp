#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/max-sum-in-the-configuration/1/

Given an array(0-based indexing), you have to find the max sum of i*A[i] where A[i] is the element at index i in the array. The only operation allowed is to rotate(clock-wise or counter clock-wise) the array any number of times.

Input:
    N = 4
    A[] = {8,3,1,2}
Output: 29
*/
/*
Method 1:
TC-O(N^2) SC-O(1) :
*/

int max_sum(int arr[], int n)
{
    int sum = 0, product_sum = 0;
    int res = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += j * arr[(i + j) % n];
        }
        res = max(res, sum);
    }

    return res;
}

/*
Method 2:
TC-O(N) SC-O(1) :
*/

int max_sum(int arr[], int n)
{
    int sum = 0, product_sum = 0;
    int res = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        product_sum += arr[i] * i;
    }

    for (int i = 0; i < n; i++)
    {
        product_sum += (sum - arr[n - i - 1] * n);
        res = max(res, product_sum);
    }

    return res;
}