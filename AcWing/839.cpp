#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
int heap[MAXN], ph[MAXN], hp[MAXN], idx, id;

inline void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(heap[a], heap[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= idx && heap[u * 2] < heap[t])
        t = u * 2;
    if (u * 2 + 1 <= idx && heap[u * 2 + 1] < heap[t])
        t = u * 2 + 1;
    if (t != u)
    {
        heap_swap(t, u);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && heap[u] < heap[u / 2])
    {
        heap_swap(u, u / 2);
        u /= 2;
    }
}

inline void insert(int num)
{
    idx++;
    id++;
    heap[idx] = num;
    ph[id] = idx;
    hp[idx] = id;
    up(idx);
}

inline int minimum()
{
    return heap[1];
}

inline void erase()
{
    heap_swap(1, idx);
    idx--;
    down(1);
}

inline void erase(int id)
{
    int k = ph[id];
    heap_swap(k, idx);
    idx--;
    up(k);
    down(k);
}

inline void modify(int id, int num)
{
    int k = ph[id];
    heap[k] = num;
    up(k);
    down(k);
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        string op;
        cin >> op;
        if (op == "I")
        {
            int x;
            cin >> x;
            insert(x);
        }
        else if (op == "PM")
        {
            cout << minimum() << endl;
        }
        else if (op == "DM")
        {
            erase();
        }
        else if (op == "D")
        {
            int k;
            cin >> k;
            erase(k);
        }
        else if (op == "C")
        {
            int k, x;
            cin >> k >> x;
            modify(k, x);
        }
    }
    return 0;
}