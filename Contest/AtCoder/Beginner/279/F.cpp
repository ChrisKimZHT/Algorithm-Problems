#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 1e6 + 10;
int N, Q;
int fa[MAXN], where[MAXN], who[MAXN];
inline void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        who[i] = i;
        where[i] = i;
    }
}

int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    init(N);
    int k = N;
    while (Q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int X, Y;
            cin >> X >> Y;
            if (who[Y] && who[X])
            {
                fa[who[Y]] = who[X];
                who[Y] = 0;
            }
            else if (who[Y])
            {
                who[X] = who[Y];
                where[who[Y]] = X;
                who[Y] = 0;
            }
        }
        else if (op == 2)
        {
            int X;
            cin >> X;
            k++;
            if (who[X] == 0) // 盒子空
            {
                who[X] = k;
                where[k] = X;
                fa[k] = k;
            }
            else // 盒子不空
            {
                fa[k] = who[X];
            }
        }
        else
        {
            int X;
            cin >> X;
            cout << where[find(X)] << endl;
        }
    }

    return 0;
}