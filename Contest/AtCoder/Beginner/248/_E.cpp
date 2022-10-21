#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int MAXN = 310;
    int N, K;
    cin >> N >> K;
    int X[MAXN], Y[MAXN];
    for (int i = 0; i < N; i++)
        cin >> X[i] >> Y[i];
    if (K == 1)
    {
        cout << "Infinity" << endl;
    }
    else
    {
        bool vis[MAXN][MAXN]{};
        int ans = 0;
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (!vis[i][j])
                {
                    vector<int> parallel;
                    parallel.push_back(i);
                    parallel.push_back(j);
                    for (int k = j + 1; k < N; k++)
                    {
                        if (((X[j] - X[i]) * (Y[k] - Y[i])) == ((Y[j] - Y[i]) * (X[k] - X[i])))
                        {
                            parallel.push_back(k);
                        }
                    }
                    for (int k = 0; k < parallel.size() - 1; k++)
                    {
                        for (int l = k + 1; l < parallel.size(); l++)
                        {
                            vis[parallel[k]][parallel[l]] = true;
                        }
                    }
                    if (parallel.size() >= K)
                        ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}