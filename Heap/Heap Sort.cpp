#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/heap-sort/1/

Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.

Input:
N = 5
arr[] = {4,1,3,9,7}
Output:
1 3 4 7 9
*/
/*
Method 1:
TC-O(N * Log(N)) SC-O(1) :
*/
class Solution
{
public:
    // Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        int largest = i;

        if (left < n && arr[largest] < arr[left])
            largest = left;
        if (right < n && arr[largest] < arr[right])
            largest = right;

        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

public:
    // Function to build a Heap from array.
    void buildHeap(int arr[], int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }

public:
    // Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);

        for (int i = n - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};