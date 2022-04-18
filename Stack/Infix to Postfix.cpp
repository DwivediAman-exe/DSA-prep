#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/

Given an infix expression in the form of string str. Convert this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -.

Input: str = "a+b*(c^d-e)^(f+g*h)-i"
Output: abcd^e-fgh*+^*+i-
*/

/*
Method 1:
TC-O(N) SC-O(N) :
*/
class Solution
{
public:
    int get_precedence(char op)
    {
        if (op == '^')
            return 3;
        else if (op == '*' || op == '/')
            return 2;
        else if (op == '+' || op == '-')
            return 1;
        else
            return 0;
    }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        string res;
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                res += s[i];
            else if (s[i] == '(')
                st.push('(');
            else if (s[i] == ')')
            {
                while (st.top() != '(')
                {
                    char temp = st.top();
                    st.pop();
                    res += temp;
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && get_precedence(st.top()) >= get_precedence(s[i]))
                {
                    res += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }

        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        return res;
    }
};