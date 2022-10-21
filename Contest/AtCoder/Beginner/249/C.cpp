#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    bool chr[20][26]{};
    for (int i = 0; i < N; i++)
    {
        string S;
        cin >> S;
        for (int j = 0; j < S.size(); j++)
            chr[i][S[j] - 'a'] = true;
    }
    int ans = 0;
    for (int i = 1; i < (1 << N); i++)
    {
        int cnt[26]{};
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                for (int k = 0; k < 26; k++)
                {
                    if (chr[j][k])
                        cnt[k]++;
                }
            }
        }
        int _ans = 0;
        for (int j = 0; j < 26; j++)
        {
            if (cnt[j] == K)
                _ans++;
        }
        ans = max(ans, _ans);
    }
    cout << ans << endl;
    return 0;
}