#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string S;
    cin >> S;
    int cnt_l = 0, cnt_r = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == 'R')
            cnt_r++;
        else
            cnt_l++;
    }
    if (!(cnt_r && cnt_l))
    {
        cout << -1 << endl;
        return;
    }
    if (S.find("RL") != S.npos)
    {
        cout << 0 << endl;
        return;
    }
    cout << S.find("LR") + 1 << endl;
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