#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B)
{
    if (B.size() > A.size())
        return add(B, A);
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 26);
        t = t > 25 ? 1 : 0;
    }
    if (t)
        C.push_back(1);
    return C;
}

void solve()
{
    string a, b;
    cin >> a >> b;
    vector<int> va, vb;
    for (int i = 0; i < a.size(); i++)
        va.push_back(a[i] - 'A');
    for (int i = 0; i < b.size(); i++)
        vb.push_back(b[i] - 'A');
    auto ans = add(va, vb);
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << char('A' + ans[i]);
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}