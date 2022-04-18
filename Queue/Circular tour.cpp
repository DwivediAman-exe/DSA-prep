#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/

Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
*/
/*
Method 1:
TC-O(N^2) SC-O(1) :
*/
class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            int j = i, curr_petrol = 0;
            while (true)
            {
                curr_petrol += p[j].petrol - p[j].distance;
                if (curr_petrol < 0)
                    break;
                j = (j + 1) % n;
                if (i == j)
                    return i;
            }
        }

        return -1;
    }
};

/*
Method 2:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        queue<int> q;
        int curr_petrol = p[0].petrol - p[0].distance, start = 0, i = 1;
        q.push(0);

        while (start != i || curr_petrol < 0)
        {
            while (curr_petrol < 0 && start != i)
            {
                curr_petrol -= (p[q.front()].petrol - p[q.front()].distance);
                q.pop();
                start = (start + 1) % n;

                if (start == 0)
                    return -1;
            }
            curr_petrol += p[i].petrol - p[i].distance;
            q.push(i);
            i = (i + 1) % n;
        }

        return start;
    }
};

/*
Method 3:
TC-O(N) SC-O(1) :
*/

class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {

        int curr_petrol = p[0].petrol - p[0].distance, start = 0, i = 1;

        while (start != i || curr_petrol < 0)
        {
            while (curr_petrol < 0 && start != i)
            {
                curr_petrol -= (p[start].petrol - p[start].distance);
                start = (start + 1) % n;

                if (start == 0)
                    return -1;
            }
            curr_petrol += p[i].petrol - p[i].distance;
            i = (i + 1) % n;
        }

        return start;
    }
};

/*
Method 4:
TC-O(N) SC-O(1) :
*/

class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {

        int curr_petrol = 0, prev_petrol = 0, start = 0;

        for (int i = 0; i < n; i++)
        {
            curr_petrol += p[i].petrol - p[i].distance;
            if (curr_petrol < 0)
            {

                start = i + 1;
                prev_petrol += curr_petrol;
                curr_petrol = 0;
            }
        }

        if ((prev_petrol + curr_petrol) >= 0)
            return start;
        else
            return -1;
    }
};