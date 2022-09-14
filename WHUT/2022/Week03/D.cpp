#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
long long ans[MAXN];
void init()
{
    for (int i = 1; i < MAXN; i++)
    {
        ans[i] = ans[i - 1];
        int t = i;
        if (!(t % 7))
            continue;
        bool flag = true;
        while (t)
        {
            if ((t % 10) == 7)
            {
                flag = false;
                break;
            }
            t /= 10;
        }
        if (!flag)
            continue;
        ans[i] += 1LL * i * i;
        // cout << ans[i] << endl;
    }
}

int main()
{
    init();
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        cout << ans[N] << endl;
    }
    return 0;
}