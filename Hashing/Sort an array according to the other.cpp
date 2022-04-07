#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/relative-sorting4323/1/

Given two integer arrays A1[ ] and A2[ ] of size N and M respectively. Sort the first array A1[ ] such that all the relative positions of the elements in the first array are the same as the elements in the second array A2[ ].
See example for better understanding.
Note: If elements are repeated in the second array, consider their first occurance only.

Input:
N = 11
M = 4
A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
A2[] = {2, 1, 8, 3}
Output:
2 2 1 1 8 8 3 5 6 7 9
*/
/*
Method 1:
TC-O(N * Log(N)) SC-O(N) :
*/
class Solution
{
public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]

    // Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M)
    {
        map<int, int> mp;

        for (int i = 0; i < N; i++)
        {
            mp[A1[i]]++;
        }

        int k = 0;

        for (int i = 0; i < M; i++)
        {
            if (mp.count(A2[i]))
            {
                int x = mp[A2[i]];

                while (x--)
                {
                    A1[k++] = A2[i];
                }

                mp.erase(A2[i]);
            }
        }

        while (mp.size() > 0)
        {
            auto it = mp.begin();

            int x = it->second;

            while (x--)
                A1[k++] = it->first;

            mp.erase(it);
        }

        return A1;
    }
};
/*
Method 2:
TC-O(N * Log(N)) SC-O(N) : Custom comparator.
*/
class Solution
{
public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]

    // Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < M; i++)
        {
            if (!mp.count(A2[i]))
                mp[A2[i]] = i + 1;
        }

        auto comp = [&](int a, int b)
        {
            if (mp[a] == 0 && mp[b] == 0)
                return a < b;
            else if (mp[a] == 0)
                return false;
            else if (mp[b] == 0)
                return true;
            else
                return mp[a] < mp[b];
        };

        sort(A1.begin(), A1.end(), comp);

        return A1;
    }
};