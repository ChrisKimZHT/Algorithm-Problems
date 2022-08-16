#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int heap[MAXN], idx, no;
int ph[MAXN], hp[MAXN];

inline void heap_swap(int a, int b)
{
    swap(heap[a], heap[b]);
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
}

void up(int x)
{
    while (x / 2 && heap[x / 2] > heap[x])
    {
        heap_swap(x / 2, x);
        x /= 2;
    }
}

void down(int x)
{
    int m = x;
    if (x * 2 <= idx && heap[m] > heap[x * 2])
        m = x * 2;
    if (x * 2 + 1 <= idx && heap[m] > heap[x * 2 + 1])
        m = x * 2 + 1;
    if (m != x)
    {
        heap_swap(m, x);
        down(m);
    }
}

void insert(int x)
{
    idx++;
    no++;
    heap[idx] = x;
    ph[no] = idx;
    hp[idx] = no;
    up(idx);
}

inline int minimum()
{
    return heap[1];
}

void erase()
{
    heap_swap(1, idx);
    idx--;
    down(1);
}

void erase(int k)
{
    int x = ph[k];
    heap_swap(x, idx);
    idx--;
    down(x);
    up(x);
}

void modify(int k, int num)
{
    int x = ph[k];
    heap[x] = num;
    down(x);
    up(x);
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