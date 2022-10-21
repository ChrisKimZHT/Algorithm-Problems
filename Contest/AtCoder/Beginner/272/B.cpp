#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
int N, M;
vector<int> attend[MAXN];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int t;
            cin >> t;
            attend[t].push_back(i);
        }
    }
    bool ans = true;
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            bool flag = false;
            for (int k = 0; k < attend[i].size(); k++)
            {
                for (int l = 0; l < attend[j].size(); l++)
                {
                    if (attend[i][k] == attend[j][l])
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (!flag)
                ans = false;
        }
        if (!ans)
            break;
    }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}