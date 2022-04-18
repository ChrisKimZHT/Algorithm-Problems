#include <bits/stdc++.h>
using namespace std;

long long px[300];
long long py[300];
bool flag[300][300];

bool colinear(int a, int b, int c)
{
    long long val1 = (py[b] - py[a]) * (px[c] - px[a]);
    long long val2 = (px[b] - px[a]) * (py[c] - py[a]);
    return (val1 == val2);
}

int main(void)
{
    int n, k, cnt, ans;
    vector<int> list;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> px[i] >> py[i];

    if (k == 1)
    {
        cout << "Infinity" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            flag[i][j] = true;
    ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (flag[i][j])
            {
                cnt = 2;
                list.clear();
                list.push_back(i);
                list.push_back(j);
                for (int ii = j + 1; ii < n; ii++)
                {
                    if (colinear(i, j, ii))
                    {
                        cnt++;
                        list.push_back(ii);
                    }
                }
                for (int ii = 0; ii < cnt; ii++)
                    for (int jj = ii + 1; jj < cnt; jj++)
                        flag[list[ii]][list[jj]] = false;
                if (cnt >= k)
                    ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
