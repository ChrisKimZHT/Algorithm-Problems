#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2022;
int stick[MAXN];

int main()
{
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++)
    {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> stick[i];
        sort(stick, stick + N);
        long long ans = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                int sum = stick[i] + stick[j];
                int tmp = lower_bound(stick, stick + N, sum) - stick - 1;
                if (tmp > j)
                    ans += tmp - j;
            }
        }
        cout << "Case " << c << ": " << ans << endl;
    }
    return 0;
}