#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1/

Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contiguous subarray sum.
Input:
N = 7
arr[] = {8,-8,9,-9,10,-11,12}
Output:
22
Explanation:
Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we
have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.

Method 1:
TC-O(N)+O(N)+O(N) ~ O(N) SC-O(1)
*/
class Solution
{
private:
    int maxSubarraySum(int arr[], int n)
    { // kadane algorithm
        int res = INT_MIN;
        int curr_sum = 0;
        for (int i = 0; i < n; i++)
        {
            curr_sum += arr[i];
            res = max(res, curr_sum);
            if (curr_sum < 0)
                curr_sum = 0;
        }
        return res;
    }

public:
    int circularSubarraySum(int arr[], int n)
    {
        int max_normal = maxSubarraySum(arr, n); // max normal subarray sum
        if (max_normal < 0)
            return max_normal;

        int arr_sum = 0;
        for (int i = 0; i < n; i++) // inverting the array
        {
            arr_sum += arr[i];
            arr[i] = -arr[i];
        }

        int max_circular = arr_sum + maxSubarraySum(arr, n);
        return max(max_normal, max_circular);
    }
};
/*
Method 2:

TC- O(N) SC-O(1)
*/
class Solution
{
public:
    // arr: input array
    // num: size of array
    // Function to find maximum circular subarray sum.
    int modifiedkadane(int arr[], int n)
    {
        int max_s = arr[0], curr_max = arr[0], min_s = arr[0], curr_min = arr[0], sum = arr[0];
        for (int i = 1; i < n; i++)
        {
            sum += arr[i];
            curr_max = max(curr_max + arr[i], arr[i]);
            max_s = max(max_s, curr_max);
            curr_min = min(curr_min + arr[i], arr[i]);
            min_s = min(min_s, curr_min);
        }
        if (min_s == sum) // all elements negative.
            return max_s;
        return max(max_s, sum - min_s);
    }
    int circularSubarraySum(int arr[], int num)
    {
        return modifiedkadane(arr, num);
    }
};