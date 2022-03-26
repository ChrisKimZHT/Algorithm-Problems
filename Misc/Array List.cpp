#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100010;

int head, idx;
int value[SIZE], nxt[SIZE];

void init()
{
    head = -1;
    idx = 0;
}

void push_front(int x)
{
    value[idx] = x;
    nxt[idx] = head;
    head = idx;
    idx++;
}

void push_back(int x)
{
    value[idx] = x;
    nxt[idx] = -1;
    int t = head;
    while (nxt[t] != -1)
        t = nxt[t];
    nxt[t] = idx;
    idx++;
}

void array_insert(int pos, int x)
{
    value[idx] = x;
    nxt[idx] = nxt[pos];
    nxt[pos] = idx;
    idx++;
}

void list_insert(int pos, int x)
{
    value[idx] = x;
    int t = head;
    for (int i = 0; i < pos; i++)
        t = nxt[t];
    nxt[idx] = nxt[t];
    nxt[t] = idx;
    idx++;
}

void erase(int pos)
{
    nxt[pos] = nxt[nxt[pos]];
}

void print()
{
    for (int i = head; i != -1; i = nxt[i])
        cout << value[i] << ' ';
    cout << endl;
}

int main(void)
{
    init();
    push_front(1);
    push_front(3);
    push_front(6);
    push_back(100);
    push_front(101);
    push_back(6);
    list_insert(3, -10);
    print();
    return 0;
}