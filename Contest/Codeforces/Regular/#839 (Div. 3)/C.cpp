#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int k, n;
    cin >> k >> n;
    vector<bool> st(n + 1);
    vector<int> ans;
    int now = 1, sum = 1;
    while (sum <= n)
    {
        ans.push_back(sum);
        st[sum] = true;
        sum += now;
        now++;
    }
    if (ans.size() < k)
    {
        int delta = k - ans.size();
        now--;
        sum -= now;
        while (n - sum < delta)
        {
            ans.pop_back();
            delta++;
            now--;
            sum -= now;
        }
        while (ans.size() < k)
            ans.push_back(++sum);
    }
    for (int i = 0; i < k; i++)
        cout << ans[i] << ' ';
    cout << endl;
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