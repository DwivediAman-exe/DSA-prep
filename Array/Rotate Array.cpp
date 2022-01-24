#include <bits/stdc++.h>
using namespace std;
/*
Ouestion Link - https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1/

Given an unsorted array arr[] of size N.
Rotate the array to the left (counter-clockwise direction) by D steps, where D is a positive integer.
Input:
N = 5, D = 2
arr[] = {1,2,3,4,5}
Output: 3 4 5 1 2

Method 1:
TC - O(ND) SC-O(1)
*/
class Solution
{
public:
    void rotateByOne(int arr[], int n)
    {
        int temp = arr[0];
        for (int i = 1; i < n; i++)
            arr[i - 1] = arr[i];
        arr[n - 1] = temp;
    }
    void rotateArr(int arr[], int d, int n)
    {
        d = d % n;
        for (int i = 0; i < d; i++)
            rotateByOne(arr, n);
    }
};
/*
Method 2:
TC - O(D)+O(N-D)+O(D) ~ O(N+D) ~ O(N)  SC-O(D)
*/
class Solution
{
public:
    void rotateArr(int arr[], int d, int n)
    {
        d = d % n;
        int temp[d];
        for (int i = 0; i < d; i++)
            temp[i] = arr[i];

        for (int i = d; i < n; i++)
            arr[i - d] = arr[i];

        for (int i = 0; i < d; i++)
            arr[n - d + i] = temp[i];
    }
};
/*
Method 3:
TC - O(D)+O(N-D)+O(N) ~ O(2N) ~ O(N) SC-O(1)
*/
class Solution
{
public:
    void reverse(int arr[], int start, int end)
    {
        while (start < end)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
    void rotateArr(int arr[], int d, int n)
    {
        d = d % n;
        reverse(arr, 0, d - 1);
        reverse(arr, d, n - 1);
        reverse(arr, 0, n - 1);
    }
};
