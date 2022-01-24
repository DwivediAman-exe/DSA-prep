#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1/

Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the elements of nums except nums[i].
Note: Try to solve this problem without using the division operation.

Input:
    n = 5
    nums[] = {10, 3, 5, 6, 2}
Output:
180 600 360 300 900
*/
/*
Method 1:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {
        vector<long long> res, left_product(n), right_product(n);

        left_product[0] = 1;
        right_product[n - 1] = 1;

        for (int i = 1; i < n; i++)
        {

            left_product[i] = left_product[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            right_product[i] = nums[i + 1] * right_product[i + 1];
        }

        for (int i = 0; i < n; i++)
        {
            res.push_back(left_product[i] * right_product[i]);
        }

        return res;
    }
};