#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<int> getans(string a, string b)
{
    vector<int> ans;
    int n = a.size();
    if (a[0] == '0')
    {
        int t = n - 1;
        while (a[t] == '0')
            t--;
        ans.push_back(t);
        a[0] = '1';
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] != b[i])
        {
            ans.push_back(-i);
            string t = a;
            for (int j = 0; j < n; j++)
            {
                if (i + j >= n)
                    break;
                if (t[j] == a[i + j])
                    a[i + j] = '0';
                else
                    a[i + j] = '1';
            }
        }
    }
    if (b[0] == '0')
    {
        int t = n - 1;
        while (a[t] == '0')
            t--;
        ans.push_back(t);
        a[0] = '0';
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    if (a.find('1') == a.npos ||
        b.find('1') == b.npos)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> ans = getans(a, b);
    if (ans.size() <= n)
    {
        cout << ans.size() << endl;
        for (auto ele : ans)
            cout << ele << ' ';
        cout << endl;
        return;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    ans = getans(a, b);
    cout << ans.size() << endl;
    for (auto ele : ans)
        cout << -ele << ' ';
    cout << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}