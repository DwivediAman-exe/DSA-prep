#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/valid-substring0624/

Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses substring.
NOTE: Length of the smallest valid substring ( ) is 2.

Input: S = "(()("
Output: 2
*/
/*
Method 1:
TC-O(N^2) SC-O(N) : For each substring check if it is valid or not.
*/

/*
Method 2:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    int findMaxLen(string s)
    {
        stack<int> st;
        st.push(-1);

        int res = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                if (!st.empty())
                    st.pop();
                if (!st.empty())
                    res = max(res, i - st.top());
                else
                    st.push(i);
            }
        }

        return res;
    }
};

/*
Method 3:
TC-O(N) SC-O(1) :
*/
class Solution
{
public:
    int findMaxLen(string s)
    {

        int res = 0, op = 0, cl = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                op++;
            else
            {
                cl++;
            }

            if (op == cl)
                res = max(res, 2 * op);
            else if (cl > op)
                op = 0, cl = 0;
        }

        op = cl = 0;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '(')
                op++;
            else
            {
                cl++;
            }

            if (op == cl)
                res = max(res, 2 * op);
            else if (cl < op)
                op = 0, cl = 0;
        }

        return res;
    }
};