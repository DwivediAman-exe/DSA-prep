#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1/

Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.

Input:
    N = 6
    arr[] = {1,2,3,4,5,6}
Output: 6 1 5 2 4 3

Method 1:
TC - O(N) , SC - O(N)
*/
// Create Separate array.
/*
Method 2:
TC - O(N) , SC - O(1)
*/
class Solution
{
public:
    void rearrange(long long arr[], int n)
    {
        int small = 0, large = n - 1;
        int key = arr[n - 1] + 1;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                arr[i] = arr[i] + (arr[large] % key) * key;
                large--;
            }
            else
            {
                arr[i] = arr[i] + (arr[small] % key) * key;
                small++;
            }
        }

        for (int i = 0; i < n; i++)
            arr[i] = arr[i] / key;
    }
};
