#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> A(M + 1);
    for (int i = 1; i <= M; i++)
        cin >> A[i];
    vector<int> pos(M + 1);
    pos[0] = 1;
    for (int i = 1; i <= M; i++)
    {
        if (A[i] == pos[i - 1])
            pos[i] = pos[i - 1] + 1;
        else if (A[i] == pos[i - 1] - 1)
            pos[i] = pos[i - 1] - 1;
        else
            pos[i] = pos[i - 1];
    }
    vector<int> where(N + 1), ans;
    for (int i = 1; i <= N; i++)
        where[i] = i;
    for (int i = M; i >= 1; i--)
    {
        ans.push_back(where[pos[i - 1]]);
        swap(where[A[i]], where[A[i] + 1]);
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << endl;
    return 0;
}