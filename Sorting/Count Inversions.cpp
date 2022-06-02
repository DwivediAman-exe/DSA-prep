#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/

Given an array of integers. Find the Inversion Count in the array.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum.
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
*/
/*
Method 1:
TC-O(N^2) SC-O(1) : Traverse through the array, and for every index, find the number of smaller elements on its right side of the array.
*/

/*
Method 2:
TC-O(N * Log(N)) SC-O(N) :
*/
class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    long long merge(long long arr[], int l, int r, int m)
    {
        vector<long long> v1, v2;
        int n1 = m - l + 1, n2 = r - m;
        long long res = 0;

        for (int i = 0; i < n1; i++)
        {
            v1.push_back(arr[l + i]);
        }
        for (int i = 0; i < n2; i++)
        {
            v2.push_back(arr[m + 1 + i]);
        }

        long long i = 0, j = 0, k = l;

        while (i < n1 && j < n2)
        {
            if (v1[i] <= v2[j])
                arr[k++] = v1[i++];
            else
            {
                arr[k++] = v2[j++];
                res += n1 - i;
            }
        }

        while (i < n1)
        {
            arr[k] = v1[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = v2[j];
            j++;
            k++;
        }

        return res;
    }

    long long mergeSort(long long arr[], long long l, long long r)
    {
        if (l < r)
        {
            long long res = 0, mid;
            mid = l + (r - l) / 2;
            res += mergeSort(arr, l, mid);
            res += mergeSort(arr, mid + 1, r);
            res += merge(arr, l, r, mid);
            return res;
        }
        else
            return 0;
    }
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr, 0, N - 1);
    }
};