#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;

long long fast_pow(long long a, long long b)
{
    a %= MOD;
    long long ans = 1;
    while (b)
    {
        if (b % 2)
        {
            ans = ans * a % MOD;
        }
        b /= 2;
        a = a * a % MOD;
    }
    return ans;
}

int main()
{
    int N, L;
    cin >> N >> L;
    bool row[18][26];
    memset(row, false, sizeof(row));
    for (int i = 0; i < N; i++)
    {
        string keys;
        cin >> keys;
        for (auto &key : keys)
            row[i][key - 'a'] = true;
    }
    long long ans = 0;
    for (int i = 1; i < (1 << N); i++)
    {
        bool these_rows[26];
        memset(these_rows, true, sizeof(these_rows));
        int selected_row_cnt = 0, selected_key_cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                selected_row_cnt++;
                for (int k = 0; k < 26; k++)
                {
                    these_rows[k] &= row[j][k];
                }
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (these_rows[i])
                selected_key_cnt++;
        }
        if (selected_row_cnt % 2)
        {
            ans += fast_pow(selected_key_cnt, L);
            ans %= MOD;
        }
        else
        {
            ans += MOD - fast_pow(selected_key_cnt, L);
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}