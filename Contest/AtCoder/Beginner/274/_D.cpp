#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, x, y;
    cin >> N >> x >> y;
    vector<int> A[2];
    int Amax[2]{};
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        A[i % 2].push_back(tmp);
        Amax[i % 2] = max(Amax[i % 2], tmp);
    }
    int offset = 1e4, size = offset * 2 + 1;
    vector<bool> dp(size), nxt(size);
    dp[offset + A[0][0]] = true;
    for (int i = 1; i < A[0].size(); i++)
    {
        nxt.assign(nxt.size(), false);
        for (int j = 0; j < size; j++)
            if (dp[j])
                nxt[j + A[0][i]] = nxt[j - A[0][i]] = true;
        dp.assign(nxt.begin(), nxt.end());
    }
    if (!dp[x + offset])
    {
        cout << "No" << endl;
        return 0;
    }
    dp.assign(size, false);
    nxt.assign(size, false);
    dp[offset] = true;
    for (int i = 0; i < A[1].size(); i++)
    {
        nxt.assign(nxt.size(), false);
        for (int j = 0; j < size; j++)
            if (dp[j])
                nxt[j + A[1][i]] = nxt[j - A[1][i]] = true;
        dp.assign(nxt.begin(), nxt.end());
    }
    if (dp[y + offset])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}