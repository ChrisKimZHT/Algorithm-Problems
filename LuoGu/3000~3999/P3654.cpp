#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
bool mat[MAXN][MAXN];

int main()
{
    int R, C, K;
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < C; j++)
            if (str[j] == '#')
                mat[i][j] = true;
    }
    int ans = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (!mat[i][j])
            {
                bool flag = true;
                for (int k = 1; k < K; k++)
                {
                    if (i + k >= R || mat[i + k][j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    ans++;
                flag = true;
                for (int k = 1; k < K; k++)
                {
                    if (j + k >= C || mat[i][j + k])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    ans++;
            }
        }
    }
    if (K == 1)
        ans /= 2;
    cout << ans << endl;
    return 0;
}