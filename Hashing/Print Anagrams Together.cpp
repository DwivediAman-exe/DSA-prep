#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/

Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

Note: The finial output will be in lexicographic order.

Input:
N = 5
words[] = {act,god,cat,dog,tac}
Output:
act cat tac
god dog
*/
/*
Method 1:
TC-O(N * M * Log(M)) SC-O(N * M) :
*/
class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        vector<vector<string>> res;

        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < string_list.size(); i++)
        {
            string word = string_list[i];

            sort(word.begin(), word.end());

            mp[word].push_back(string_list[i]);
        }

        for (auto x : mp)
        {
            vector<string> row;
            for (int i = 0; i < x.second.size(); i++)
            {
                row.push_back(x.second[i]);
            }
            res.push_back(row);
        }

        return res;
    }
};
/*
Method 2:
TC-O(N * M) SC-O(N * M) :
*/

class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        vector<vector<string>> res;

        map<map<char, int>, vector<string>> mp;

        for (int i = 0; i < string_list.size(); i++)
        {
            map<char, int> s_m;

            string word = string_list[i];

            for (auto ch : word)
                s_m[ch]++;

            mp[s_m].push_back(string_list[i]);
        }

        for (auto x : mp)
        {
            vector<string> row;
            for (int i = 0; i < x.second.size(); i++)
            {
                row.push_back(x.second[i]);
            }
            res.push_back(row);
        }

        return res;
    }
};

/*
Alternative - Use Trie
*/