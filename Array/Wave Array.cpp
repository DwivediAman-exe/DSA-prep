#include <bits/stdc++.h>
using namespace std;

// Question Link - https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1/#
// Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array and return it
// In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5].....
// If there are multiple solutions, find the lexicographically smallest one.
// Input:
// n = 5
// arr[] = {1,2,3,4,5}
// Output: 2 1 4 3 5

// if array is not sorted , sort it then TC - O(N*long(N)) or refer to method 2

// Method 1:
// TC - O(N), SC-O(1)

class Solution
{
public:
	void convertToWave(vector<int> &arr, int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			swap(arr[i], arr[i + 1]);
			i++;
		}
	}
};

// Method 2:                 for unsorted array
// TC - O(N), SC-O(1)

class Solution
{
public:
	void convertToWave(vector<int> &arr, int n)
	{
		for (int i = 0; i < n; i += 2) // for even elements should be greater than their adjacents
		{
			if (i > 0 && arr[i - 1] > arr[i])
				swap(arr[i], arr[i - 1]);

			if (i < n - 1 && arr[i] < arr[i + 1])
				swap(arr[i], arr[i + 1]);
		}
	}
};
