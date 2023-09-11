// Problem: D2. Candy Party (Hard Version)
// Contest: Codeforces - Codeforces Round 896 (Div. 2)
// URL: https://codeforces.com/contest/1869/problem/D2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

pair<int, int> bin_split(int x)
{
    int start = -1;
    int t = x, digit = 0;
    while (t)
    {
        digit++;
        t /= 2;
    }
    for (int i = 0; i < digit; i++)
    {
        if (start == -1 && (x >> i & 1) == 1)
        {
            start = i;
        }
        else if (start != -1 && (x >> i & 1) == 0)
        {
            return {-1, -1};
        }
    }
    return {start, digit};
}

int log_2(int x)
{
    int num = 1, pow = 0;
    while (num < x)
    {
        num *= 2;
        pow++;
    }
    return num == x ? pow : -1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int sum = accumulate(a.begin() + 1, a.begin() + 1 + n, 0LL);
    if (sum % n)
    {
        cout << "No" << endl;
        return;
    }
    int mean = sum / n;
    vector<int> remain(40), add(40), sub(40);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == mean)
            continue;
        int delta = abs(a[i] - mean);
        int pow = log_2(delta);
        if (pow != -1)
        {
            if (a[i] > mean)
                sub[pow]++;
            else
                add[pow]++;
            continue;
        }
        auto splt = bin_split(delta);
        if (splt.first == -1)
        {
            cout << "No" << endl;
            return;
        }
        if (a[i] > mean)
        {
            remain[splt.first]--;
            remain[splt.second]++;
        }
        else
        {
            remain[splt.first]++;
            remain[splt.second]--;
        }
    }
    for (int i = 31; i >= 0; i--)
    {
        remain[i] += sub[i];
        remain[i] -= add[i];
        if (i == 0)
            break;
        if (remain[i] < 0)
        {
            sub[i - 1] += remain[i];
            remain[i - 1] += remain[i];
            if (sub[i - 1] < 0)
            {
                cout << "No" << endl;
                return;
            }
        }
        else
        {
            add[i - 1] -= remain[i];
            remain[i - 1] += remain[i];
            if (add[i - 1] < 0)
            {
                cout << "No" << endl;
                return;
            }
        }
    }
    if (remain[0] == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}