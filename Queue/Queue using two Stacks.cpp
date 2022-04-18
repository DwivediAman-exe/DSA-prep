#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/queue-using-two-stacks

Implement a Queue using 2 stacks s1 and s2 .
A Query Q is of 2 Types
(i) 1 x (a query of this type means  pushing 'x' into the queue)
(ii) 2   (a query of this type means to pop element from queue and print the poped element)

Input:
4
1 2 2 2 1 4

Output:
2 -1
*/
/*
Method 1:
TC-O(N) for 1 operation and O(1) for other.
SC-O(1)
*/

void StackQueue ::push(int x)
{
    s1.push(x);
}

// Function to pop an element from queue by using 2 stacks.
int StackQueue ::pop()
{
    if (s2.empty())
    {
        while (!s1.empty())
        {
            int temp = s1.top();
            s1.pop();
            s2.push(temp);
        }

        if (s2.empty())
        {
            return -1;
        }
        else
        {
            int temp = s2.top();
            s2.pop();
            return temp;
        }
    }
    else
    {
        int temp = s2.top();
        s2.pop();
        return temp;
    }
}