#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/

You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

Input:
push(2)
push(3)
pop()
getMin()
push(1)
getMin()
Output: 3 2 1
*/
/*
Method 1:
TC-O(1) SC-O(1) :
*/

class Solution
{
    int minEle;
    stack<int> s;

public:
    /*returns min element from stack*/
    int getMin()
    {

        if (s.empty())
            return -1;
        else
        {
            return minEle;
        }
    }

    /*returns poped element from stack*/
    int pop()
    {

        if (s.size() == 0)
            return -1;
        else
        {
            int temp = s.top();
            s.pop();

            if (temp > minEle)
                return temp;

            else
            {
                int res = minEle;
                minEle = 2 * minEle - temp;
                return res;
            }
        }
    }

    /*push element x into the stack*/
    void push(int x)
    {

        if (s.size() == 0)
        {
            minEle = x;
            s.push(x);
        }
        else
        {
            if (x < minEle)
            {
                int y = 2 * x - minEle;
                minEle = x;
                s.push(y);
            }
            else
                s.push(x);
        }
    }
};