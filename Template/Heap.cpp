#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
int heap[MAXN], idx;

void down(int u)
{
    int t = u;
    if (u * 2 <= idx && heap[u * 2] < heap[t])
        t = u * 2;
    if (u * 2 + 1 <= idx && heap[u * 2 + 1] < heap[t])
        t = u * 2 + 1;
    if (t != u)
    {
        swap(heap[t], heap[u]);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && heap[u] < heap[u / 2])
    {
        swap(heap[u], heap[u / 2]);
        u /= 2;
    }
}

int main()
{
    return 0;
}