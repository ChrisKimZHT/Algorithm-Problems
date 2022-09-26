#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int N, diff[MAXN];

int main()
{
    while (cin >> N, N)
    {
        memset(diff, 0, sizeof(diff));
        for (int i = 0; i < N; i++)
        {
            int a, b;
            cin >> a >> b;
            diff[a]++;
            diff[b + 1]--;
        }
        int tmp = 0;
        for (int i = 1; i <= N; i++)
        {
            if (i - 1)
                cout << ' ';
            tmp += diff[i];
            cout << tmp;
        }
        cout << endl;
    }
    return 0;
}