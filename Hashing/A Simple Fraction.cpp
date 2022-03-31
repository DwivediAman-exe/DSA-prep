#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/a-simple-fraction0921/1/

Given a fraction. Convert it into a decimal.
If the fractional part is repeating, enclose the repeating part in parentheses.

Input: numerator = 1, denominator = 3
Output: "0.(3)"
*/
/*
Method 1:
TC-O(k) SC-O(k) :  k->constant
*/
class Solution
{
public:
    string fractionToDecimal(int num, int den)
    {

        int q = num / den, rem = num % den;
        string dec, integ = to_string(q);

        unordered_map<int, int> mp;

        if (rem == 0)
            return integ;

        while (rem != 0)
        {
            if (mp.find(rem) != mp.end())
            {
                dec.insert(mp[rem], "(");
                dec += ')';
                break;
            }
            else
            {
                mp[rem] = dec.length();

                rem *= 10;
                int in = rem / den;

                rem = rem % den;
                dec += to_string(in);
            }
        }

        return integ + '.' + dec;
    }
};