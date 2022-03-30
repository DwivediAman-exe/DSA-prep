#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/word-ladder/1/

Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList.
The second part of this problem can be found here.

Input:
wordList = {"des","der","dfr","dgt","dfs"}
startWord = "der", targetWord= "dfs",
Output:
3
*/
/*
Method 1:
TC-O(N^2 * M) SC-O(N * M) :
*/
class Solution
{
public:
    vector<string> getDiff(string word, vector<string> &wordList)
    {
        vector<string> res;

        for (auto &b : wordList)
        {
            if (b == word)
            {
                b = "";
            }
            else
            {
                int x = 0;

                for (int i = 0; i < word.length(); i++)
                {
                    if (word[i] != b[i])
                        x++;
                }

                if (x == 1)
                {
                    res.push_back(b);
                    b = "";
                }
            }
        }

        return res;
    }

    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        q.push({startWord, 1});

        while (!q.empty())
        {
            string curr = q.front().first;
            int move = q.front().second;
            q.pop();

            if (curr == targetWord)
                return move;

            vector<string> res = getDiff(curr, wordList);

            for (string y : res)
            {
                q.push({y, move + 1});
            }
        }

        return 0;
    }
};
