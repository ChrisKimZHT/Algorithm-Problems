#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int q;
    cin >> q;
    bool st_s = false, st_t = false;
    long long cnt_s = 1, cnt_t = 1;
    while (q--)
    {
        int d, k;
        string x;
        cin >> d >> k >> x;
        if (d == 1)
        {
            for (auto &c : x)
            {
                if (c == 'a')
                    cnt_s += k;
                else
                    st_s = true;
            }
        }
        else
        {
            for (auto &c : x)
            {
                if (c == 'a')
                    cnt_t += k;
                else
                    st_t = true;
            }
        }
        if (st_t)
            cout << "Yes" << endl;
        else if (!st_s && cnt_s < cnt_t)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}