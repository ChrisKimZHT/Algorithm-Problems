#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int Q;
    cin >> Q;
    while (Q--)
    {
        int L, R, X;
        cin >> L >> R >> X;
        int ans = 0;
        for (int i = L - 1; i < R; i++)
        {
            if (A[i] == X)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}