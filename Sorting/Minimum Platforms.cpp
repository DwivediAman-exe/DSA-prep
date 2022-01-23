#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1/

Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.

Input: n = 6
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3

*/
/*
Method 1:
TC-O(N^2) SC-O(1) :

Check for each train, the number of overlapping trains.
*/

/*
Method 2:
TC-O(N*Log(N)) SC-O(N) :
*/

struct Event
{
    int time_val;
    bool isarrival;
};

bool mycomp(Event a, Event b)
{
    if (a.time_val < b.time_val)
        return true;
    else if (a.time_val == b.time_val && b.isarrival)
        return false;
    else if (a.time_val == b.time_val && a.isarrival)
        return true;
    return false;
}
class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        Event events[2 * n];

        for (int i = 0; i < n; i++)
        {
            events[i].time_val = arr[i];
            events[i].isarrival = true;

            events[i + n].time_val = dep[i];
            events[i + n].isarrival = false;
        }

        sort(events, events + 2 * n, mycomp);

        int res = 0, count = 0;

        for (int i = 0; i < 2 * n; i++)
        {
            if (events[i].isarrival)
                count++;
            else
                count--;

            res = max(res, count);
        }

        return res;
    }
};

/*
Method 3:
TC-O(N*Log(N)) SC-O(1) :
*/

class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int plat_needed = 0, curr_count = 0;

        int i = 0, j = 0;

        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
            {
                curr_count++;
                i++;
            }
            else
            {
                curr_count--;
                j++;
            }

            plat_needed = max(curr_count, plat_needed);
        }

        return plat_needed;
    }
};