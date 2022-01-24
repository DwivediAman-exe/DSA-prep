#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1/

Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers.

Input:
N = 2
arr[] = {1, 2, 3, 2, 1, 4}
Output: 3 4


Method 1:
TC - O(N) , SC - O(1) (No modification in the array.)
*/
class Solution
{
public:
    vector<int> singleNumber(vector<int> arr)
    {
        int size = arr.size();
        int n = (size - 2) / 2;
        int Xor = 0;
        for (int i = 0; i < size; i++)
        {
            Xor ^= arr[i];
        }
        int set_bit = Xor & ~(Xor - 1);
        int x = 0, y = 0;
        for (int i = 0; i < size; i++)
        {
            if (set_bit & arr[i])
                x ^= arr[i];
            else
                y ^= arr[i];
        }
        return {min(x, y), max(x, y)};
    }
};
