#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), ldiff(n), rdiff(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ldiff.front() = a.front() + 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
            ldiff[i] = ldiff[i - 1];
        else
            ldiff[i] = a[i - 1];
    }
    rdiff.back() = a.back() + 1;
    for (int i = a.size() - 2; i >= 0; i--)
    {
        if (a[i] == a[i + 1])
            rdiff[i] = rdiff[i + 1];
        else
            rdiff[i] = a[i + 1];
    }
    // for (int i = 0; i < n; i++)
    //     cout << ldiff[i] << ' ';
    // cout << endl;
    // for (int i = 0; i < n; i++)
    //     cout << rdiff[i] << ' ';
    // cout << endl;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if ((!i || ldiff[i - 1] != ldiff[i] || rdiff[i - 1] != rdiff[i]) &&
            ldiff[i] > a[i] && rdiff[i] > a[i])
            cnt++;
    if (cnt == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}