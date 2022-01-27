#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/possible-groups2013/1/

Given an array of positive integers of size N, form groups of two or three such that the sum of all elements in a group is a multiple of 3. Count all possible number of groups that can be generated in this way.

Input:
    N = 5
    arr[] = {3, 6, 7, 2, 9}
Output: 8
*/

/*
Method 1:
TC-O(N) SC-O(1) :
*/

class Solution
{
public:
    long long findgroups(int arr[], int n)
    {

        long long mod_1 = 0, mod_2 = 0, mod_0 = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 3 == 0)
                mod_0++;
            else if (arr[i] % 3 == 1)
                mod_1++;
            else
                mod_2++;
        }

        long long group_2 = (mod_0 - 1) * mod_0 / 2 + mod_1 * mod_2;
        long long group_3 = (mod_1 - 2) * (mod_1 - 1) * mod_1 / 6 + (mod_2 - 2) * (mod_2 - 1) * mod_2 / 6 +
                            (mod_0 - 2) * (mod_0 - 1) * mod_0 / 6 +
                            mod_1 * mod_2 * mod_0;

        return group_2 + group_3;
    }
};