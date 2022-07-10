#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int ans = 0, coin = 0;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        if (coin + tmp <= M)
        {
            coin += tmp;
        }
        else
        {
            coin = tmp;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}