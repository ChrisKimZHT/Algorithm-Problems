#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> player(N + 1);
    while (Q--)
    {
        int op, x;
        cin >> op >> x;
        if (op == 1)
        {
            if (player[x] != -1)
                player[x]++;
            if (player[x] >= 2)
                player[x] = -1;
        }
        else if (op == 2)
        {
            player[x] = -1;
        }
        else
        {
            if (player[x] == -1)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}