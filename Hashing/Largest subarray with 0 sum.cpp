#include<bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1/

Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Input:
    N = 8
    A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
*/
/*
Method 1:

TC - O(N*N) SC-(1)
*/
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int len=0;
        
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s+=A[j];
                if(s==0)len=max(len,j-i+1);
            }
        }
        return len;
    }
};


/*
Method 2:

TC - O(N) SC-O(N)
*/
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int s=0,len=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(int i=0;i<n;i++)
        {
            s+=A[i];
            if(mp.find(s)==mp.end())
                mp[s]=i;
            else 
                len=max(len,i-mp[s]);
        }
        return len;
    }
};
