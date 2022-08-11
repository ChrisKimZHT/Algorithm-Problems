#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
int n, k;
int val[MAXN];
// int q[MAXN], h = 0, t = -1;
deque<int> q;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> val[i];
    // for (int i = 0; i < n; i++)
    // {
    //     while (h <= t && val[q[t]] > val[i])
    //         t--;
    //     q[++t] = i;
    //     if (i >= k - 1)
    //     {
    //         if (q[h] < i - k + 1)
    //             h++;
    //         cout << val[q[h]] << ' ';
    //     }
    // }
    // cout << endl;
    // h = 0, t = -1;
    // for (int i = 0; i < n; i++)
    // {
    //     while (h <= t && val[q[t]] < val[i])
    //         t--;
    //     q[++t] = i;
    //     if (i >= k - 1)
    //     {
    //         if (q[h] < i - k + 1)
    //             h++;
    //         cout << val[q[h]] << ' ';
    //     }
    // }
    // cout << endl;
    for (int i = 0; i < n; i++)
    {
        while (!q.empty() && val[q.back()] > val[i])
            q.pop_back();
        q.push_back(i);
        if (i >= k - 1)
        {
            if (q.front() < i - k + 1)
                q.pop_front();
            cout << val[q.front()] << ' ';
        }
    }
    cout << endl;
    q.clear();
    for (int i = 0; i < n; i++)
    {
        while (!q.empty() && val[q.back()] < val[i])
            q.pop_back();
        q.push_back(i);
        if (i >= k - 1)
        {
            if (q.front() < i - k + 1)
                q.pop_front();
            cout << val[q.front()] << ' ';
        }
    }
    cout << endl;
    return 0;
}