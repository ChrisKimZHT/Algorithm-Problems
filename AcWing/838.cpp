#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
int heap[MAXN], idx;

void down(int n)
{
    int t = n;
    if (n * 2 <= idx && heap[n * 2] < heap[t])
        t = n * 2;
    if (n * 2 + 1 <= idx && heap[n * 2 + 1] < heap[t])
        t = n * 2 + 1;
    if (t != n)
    {
        swap(heap[t], heap[n]);
        down(t);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> heap[i];
    idx = n;
    for (int i = n / 2; i > 0; i--)
        down(i);
    while (m--)
    {
        cout << heap[1] << ' ';
        heap[1] = heap[idx--];
        down(1);
    }
    return 0;
}