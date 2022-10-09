#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
int N, M;
int A[MAXN];
vector<int> ans[MAXN];
bool st[MAXN];

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
    {
        if (A[i] >= N)
            continue;
        int a = A[i] >= 0 ? 1 : (-A[i] + (i - 1)) / i; // + (i - 1): 向上取整
        int b = min(M, (N - A[i] + (i - 1)) / i);
        for (int j = a; j <= b; j++)
            ans[j].push_back(A[i] + j * i);
    }
    for (int i = 1; i <= M; i++)
    {
        memset(st, false, sizeof(st));
        for (int j = 0; j < ans[i].size(); j++)
            if (ans[i][j] <= N)
                st[ans[i][j]] = true;
        int res = 0;
        while (st[res])
            res++;
        cout << res << endl;
    }
    return 0;
}
