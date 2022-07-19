#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    if (2 * K > N)
    {
        cout << -1 << endl;
        return 0;
    }
    int cnt = 0;
    while (N - cnt >= 4 * K)
    {
        for (int i = 1; i <= K; i++)
            cout << cnt + i + K << ' ';
        for (int i = 1; i <= K; i++)
            cout << cnt + i << ' ';
        cnt += 2 * K;
    }
    if (N - cnt <= 3 * K)
    {
        int i = 1;
        for (; i <= (N - cnt) - K; i++)
            cout << i + K + cnt << ' ';
        for (; i <= (N - cnt); i++)
            cout << i - (N - cnt) + K + cnt << ' ';
    }
    else
    {
        int i = 1;
        for (; i <= K; i++)
            cout << i + K + cnt << ' ';
        for (; i <= (N - cnt) - 2 * K; i++)
            cout << i - K + cnt << ' ';
        for (; i <= (N - cnt) - K; i++)
            cout << i + K + cnt << ' ';
        for (; i <= 3 * K; i++)
            cout << i - 2 * K + cnt << ' ';
        for (; i <= (N - cnt); i++)
            cout << i - K + cnt << ' ';
    }
    cout << endl;
    return 0;
}