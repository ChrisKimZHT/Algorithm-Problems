#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> idx(N + 1);
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        idx[num].push_back(i);
    }
    int Q;
    cin >> Q;
    while (Q--)
    {
        int L, R, X;
        cin >> L >> R >> X;
        cout << lower_bound(idx[X].begin(), idx[X].end(), R) - lower_bound(idx[X].begin(), idx[X].end(), L - 1) << endl;
    }
    return 0;
}