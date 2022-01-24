#include <bits/stdc++.h>
using namespace std;

// Question Link - https: //practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1/#

// Given an array A of n positive numbers. The task is to find the first Equilibium Point in the array.
// Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.
// Input:
// n = 5
// A[] = {1,3,5,2,2}
// Output: 3
// Explanation 1+3 = 2+2

// Method 1:
// TC - O(N*N), SC - O(1)

class Solution
{
public:
	int equilibriumPoint(long long a[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			long long sum1 = 0, sum2 = 0;
			for (int j = 0; j < i; j++)
				sum1 += a[j];

			for (int j = i + 1; j < n; j++)
				sum2 += a[j];

			if (sum1 == sum2)
				return i + 1;
		}
		return -1;
	}
};

// Method 2:
// TC - O(N), SC - O(1)

class Solution
{
public:
	int equilibriumPoint(long long a[], int n)
	{
		long long total_sum = 0;
		for (int i = 0; i < n; i++)
			total_sum += a[i];

		long long left_sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (left_sum == total_sum - a[i])
				return i + 1;
			left_sum += a[i];
			total_sum -= a[i];
		}
		return -1;
	}
};
