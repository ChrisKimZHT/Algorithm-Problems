#include <bits/stdc++.h>
#define endl '\n'

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
        C.push_back(t % (i + 2));
        t = t > i + 1 ? 1 : 0;
    }
    if (t)
        C.push_back(1);
    return C;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
        cin >> a[n - i - 1];
    for (int i = 0; i < m; i++)
        cin >> b[m - i - 1];
    vector<int> ans = add(a, b);
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}