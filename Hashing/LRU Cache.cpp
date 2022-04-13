#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/lru-cache/1/

Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types:

SET x y : sets the value of the key x with value y
GET x : gets the key of x if present else returns -1.

The LRUCache class has two methods get() and set() which are defined as follows.

get(key)   : returns the value of the key if it already exists in the cache otherwise returns -1.
set(key, value) : if the key is already present, update its value. If not present, add the key-value pair to the cache. If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.
In the constructor of the class the capacity of the cache should be intitialized.

Input:
cap = 2
Q = 2
Queries = SET 1 2 GET 1
Output: 2
*/
/*
Method 1:
TC-O(1) SC-O(N) :
*/
struct Node
{
    int key;
    int value;

    Node(int k, int v)
    {
        key = k;
        value = v;
    }
};

class LRUCache
{
private:
    list<Node> dq;
    unordered_map<int, list<Node>::iterator> mp;
    int capacity;

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capacity = cap;
    }

    // Function to return value corresponding to the key.
    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        else
        {
            Node it = *mp[key];
            dq.erase(mp[key]);
            dq.push_front(it);
            mp[key] = dq.begin();
            return it.value;
        }
    }

    // Function for storing key-value pair.
    void set(int key, int value)
    {
        if (mp.find(key) == mp.end())
        {
            if (dq.size() == capacity)
            {
                Node last = dq.back();
                dq.pop_back();
                mp.erase(last.key);
            }
        }
        else
            dq.erase(mp[key]);
        Node it(key, value);
        dq.push_front(it);
        mp[key] = dq.begin();
    }
};
/*
Method 2:
TC-O(1) SC-O(N) :
*/
class LRUCache
{
private:
    struct Node
    {
        int key;
        int value;
        Node *prev, *next;

        Node(int k, int v)
        {
            key = k;
            value = v;
            prev = next = NULL;
        }
    };
    Node *head = NULL;
    Node *tail = NULL;
    unordered_map<int, Node *> mp;
    int capacity;

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capacity = cap;
    }

    void addNode(Node *newNode)
    {
        if (!head)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void deleteNode(Node *delNode)
    {

        if (head == delNode)
        {
            head = head->next;
        }
        else if (tail == delNode)
        {
            tail = delNode->prev;
        }

        if (delNode->prev != NULL)
            delNode->prev->next = delNode->next;
        if (delNode->next != NULL)
            delNode->next->prev = delNode->prev;
        delete (delNode);
    }

    // Function to return value corresponding to the key.
    int get(int key)
    {

        if (mp.find(key) == mp.end())
            return -1;
        else
        {
            Node *it = mp[key];
            Node *newNode = new Node(key, it->value);
            deleteNode(it);
            addNode(newNode);
            mp[key] = newNode;
            return newNode->value;
        }
    }

    // Function for storing key-value pair.
    void set(int key, int value)
    {
        if (mp.find(key) == mp.end())
        {
            if (mp.size() == capacity)
            {
                int temp = tail->key;
                deleteNode(tail);
                mp.erase(temp);
            }
        }
        else
            deleteNode(mp[key]);
        Node *it = new Node(key, value);
        addNode(it);
        mp[key] = head;
    }
};