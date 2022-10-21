#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int MAXN = 1e3 + 10;
    int N, M;
    cin >> N >> M;
    int T[MAXN];
    int last[MAXN];
    memset(last, -1, sizeof(last));
    for (int i = 1; i <= N; i++)
    {
        cin >> T[i];
    }
    for (int i = 1; i <= M; i++)
    {
        int t, k;
        cin >> t >> k;
        for (int j = 0; j < k; j++)
        {
            int medi;
            cin >> medi;
            if ((last[medi] == -1 || T[medi] == -1 || last[medi] + T[medi] <= t))
            {
                last[medi] = t;
            }
            else
            {
                cout << "Don't take " << medi << " at " << t << "!" << endl;
            }
        }
    }
    return 0;
}