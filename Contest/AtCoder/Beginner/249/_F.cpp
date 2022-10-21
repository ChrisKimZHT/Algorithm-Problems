#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
int N, K;
int t[MAXN], y[MAXN];
priority_queue<int> pque;

int main()
{
    cin >> N >> K;
    for (int i = N; i > 0; i--)
        cin >> t[i] >> y[i];
    long long ans = INT64_MIN, added = 0;
    for (int i = 1; i <= N; i++)
    {
        if (t[i] == 2)
        {
            if (y[i] >= 0)
                added += y[i];
            else
                pque.push(y[i]);
        }
        else
        {
            ans = max(ans, y[i] + added);
            K--;
        }
        while (pque.size() > K)
        {
            added += pque.top();
            pque.pop();
        }
        if (K < 0)
            break;
    }
    if (K >= 0)
        ans = max(ans, added);
    cout << ans << endl;
    return 0;
}