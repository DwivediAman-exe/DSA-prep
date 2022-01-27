#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space1004/1/

Given a N x N 2D matrix Arr representing an image. Rotate the image by 90 degrees (anti-clockwise). You need to do this in place. Note that if you end up using an additional array, you will only receive partial score.

Input:
N = 3
Arr[][] = {{1,  2,  3}
           {4,  5,  6}
           {7,  8,  9}}
Output:
 3  6  9
 2  5  8
 1  4  7
*/
/*
Method 1:
TC-O(N^2) SC-O(1) :
*/
class Solution
{
public:
    void rotateMatrix(vector<vector<int>> &arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(arr[i][j], arr[j][i]);
            }
        }

        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                swap(arr[i][j], arr[n - i - 1][j]);
            }
        }
    }
};