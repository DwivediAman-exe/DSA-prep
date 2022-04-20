#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/peak-element

An element is called a peak element if its value is not smaller than the value of its adjacent elements(if they exists).
Given an array arr[] of size N, find the index of any one of its peak elements.
Note: The generated output will always be 1 if the index that you return is correct. Otherwise output will be 0.

Input:
N = 3
arr[] = {1,2,3}
Output: 2
*/
/*
Method 1:
TC-O(N) SC-O(1) : Check for all elements linearly.
*/

/*
Method 2:
TC-O(log(N)) SC-O(1) :
*/
class Solution
{
public:
    int peakElement(int arr[], int n)
    {
        int low = 0, high = n - 1, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (
                (mid == 0 && arr[mid] >= arr[mid + 1]) ||
                (mid > 0 && mid < n - 1 && arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1]) ||
                (mid == n - 1 && arr[mid] >= arr[mid - 1]))
            {
                return mid;
            }
            else if (arr[mid] <= arr[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};