#include <bits/stdc++.h>
using namespace std;

// Question Link - https://practice.geeksforgeeks.org/problems/reverse-array-in-groups0255/1/
// Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.
// Input:
// N = 5, K = 3
// arr[] = {1,2,3,4,5}
// Output: 3 2 1 5 4

//  Method 1:
// TC - O(N), SC - O(N)

class Solution
{
public:
	void reverse(vector<long long> &a, int low, int high)
	{
		while (low < high)
		{
			long long temp = a[low];
			a[low] = a[high];
			a[high] = temp;
			low++;
			high--;
		}
	}
	void reverseInGroups(vector<long long> &arr, int n, int k)
	{
		int h = k - 1, l = 0;
		while (h < n)
		{
			reverse(arr, l, h);
			l += k;
			h += k;
		}
		if (l < n)
			reverse(arr, l, n - 1);
	}
};