#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e5 + 10;
int N, M, T;
int A[MAXN];

signed main()
{
    cin >> N >> M >> T;
    for (int i = 1; i < N; i++)
        cin >> A[i];
    bool flag = true;
    int now = 1;
    for (int i = 1; i <= M; i++)
    {
        int X, Y;
        cin >> X >> Y;
        int sum = 0;
        for (int j = now; j < X; j++)
            sum += A[j];
        if (sum < T)
        {
            T -= sum;
            T += Y;
            now = X;
        }
        else
        {
            flag = false;
        }
    }
    if (flag)
    {
        int sum = 0;
        for (int i = now; i < N; i++)
            sum += A[i];
        if (sum >= T)
            flag = false;
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}