#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/count-the-reversals0401/

Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Input:
S = "}{{}}{{{"
Output: 3
*/
/*
Method 1:
TC-O(N) SC-O(N) :
*/
int countRev(string s)
{
    stack<char> st;
    int n = s.length();

    if (n % 2)
        return -1;

    for (int i = 0; i < n; i++)
    {
        if (!st.empty() && s[i] == '}')
        {
            if (st.top() == '{')
                st.pop();
            else
                st.push('}');
        }
        else
            st.push(s[i]);
    }

    int op = 0, cl = 0;

    while (!st.empty())
    {
        if (st.top() == '}')
            cl++;
        else
            op++;
        st.pop();
    }

    return ceil(op / 2.0) + ceil(cl / 2.0);
}

/*
Alternative Approach :
*/

int countRev(string s)
{
    stack<char> st;
    int n = s.length(), ans = 0;

    if (n % 2)
        return -1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
                st.pop();
            else
            {
                ans++;
                st.push('{');
            }
        }
        else
            st.push(s[i]);
    }

    return ans + st.size() / 2;
}
/*
Method 2:
TC-O(N) SC-O(1) :
*/
int countRev(string s)
{

    int n = s.length(), temp = 0, ans = 0;

    if (n % 2)
        return -1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '}')
        {
            if (temp != 0)
                temp--;
            else
            {
                ans++;
                temp++;
            }
        }
        else
            temp++;
    }

    return ans + temp / 2;
}