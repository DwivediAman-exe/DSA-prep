#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/355f731797ea1acbd5ab698b19eb1c3c469aa837/

There are N buildings in Linear Land. They appear in a linear line one after the other and their heights are given in the array arr[]. Geek wants to select three buildings in Linear Land and remodel them as recreational spots. The third of the selected building must be taller than the first and shorter than the second.
Can geek build the three-building recreational zone?

Input:
N = 6
arr[] = {4, 7, 11, 5, 13, 2}
Output:
True
*/
/*
Method 1:
TC-O(N^2) SC-O(1) : Find previous smallest and next greatest number smaller than current number. If it exists return True.
*/

/*
Method 2:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    bool recreationalSpot(int arr[], int n)
    {
        int prev_max = -1;
        vector<int> res(n);

        for (int i = 0; i < n; i++)
        {
            if (prev_max == -1)
            {
                res[i] = prev_max = arr[i];
            }
            else
            {
                prev_max = min(prev_max, arr[i]);
                res[i] = prev_max;
            }
        }

        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            if (res[i] < arr[i])
            {
                while (!st.empty() && st.top() <= res[i])
                    st.pop();
                if (!st.empty() && st.top() < arr[i])
                    return true;
            }
            st.push(arr[i]);
        }
        return false;
    }
};