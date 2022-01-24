#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1/

Given an array arr[] of N positive integers.
Push all the zero’s of the given array to the right end of the array while maitaining the order of non-zero elements.
Input:
N = 5
Arr[] = {3, 5, 0, 0, 4}
Output: 3 5 4 0 0

Method 1:
TC-O(N*N) SC-O(1)
*/
class Solution
{
public:
	void pushZerosToEnd(int arr[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i] == 0)
			{
				for (int j = i + 1; j < n; j++)
				{
					if (arr[j] != 0)
					{
						swap(arr[i], arr[j]);
						break;
					}
				}
			}
		}
	}
};
/*
Method 2:
TC-O(N) SC-O(1)
*/
class Solution
{
public:
	void pushZerosToEnd(int arr[], int n)
	{
		int count = 0; // count of non-zero elements is equal to position of first zero
		for (int i = 0; i < n; i++)
		{
			if (arr[i] != 0)
			{
				swap(arr[i], arr[count]);
				count++;
			}
		}
	}
};
