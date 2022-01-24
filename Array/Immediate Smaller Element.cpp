#include <bits/stdc++.h>
using namespace std;
/*
Questions Link - https://practice.geeksforgeeks.org/problems/immediate-smaller-element1142/1

Given an integer array Arr of size N. For each element in the array, check whether the right adjacent element (on the next immediate position) of the array is smaller.
If next element is smaller, update the current index to that element. If not, then  -1.
Input:
  N = 5
  Arr[] = {4, 2, 1, 5, 3}
Output:
  2 1 -1 3 -1

Method 1 :

TC - O(N) , SC - O(1)
*/
class Solution
{
public:
	void immediateSmaller(int *arr, int n)
	{
		for (int i = 1; i < n; i++)
		{
			if (arr[i - 1] > arr[i])
				arr[i - 1] = arr[i];
			else
				arr[i - 1] = -1;
		}
		arr[n - 1] = -1;
	}
};
