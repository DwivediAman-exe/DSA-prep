#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/

Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

Input: S = "231*+9-"
Output: -4
*/

/*
Method 1:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    // Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> st;
        int n = S.length();

        for (int i = 0; i < n; i++)
        {
            if (S[i] >= '0' && S[i] <= '9')
                st.push(S[i] - '0');
            else
            {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();

                if (S[i] == '+')
                    st.push(first + second);
                else if (S[i] == '-')
                    st.push(second - first);
                else if (S[i] == '*')
                    st.push(first * second);
                else if (S[i] == '/')
                    st.push(second / first);
            }
        }

        return st.top();
    }
};