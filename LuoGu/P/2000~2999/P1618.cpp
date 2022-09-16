#include <bits/stdc++.h>

using namespace std;

int a, b, c;
bool vis[10];
int num[3];
bool flag;

void dfs(int x)
{
    if (x == 10)
    {
        if (!(num[0] % a) && !(num[1] % b) && !(num[2] % c) &&
            (num[0] / a == num[1] / b) && (num[1] / b == num[2] / c))
        {
            cout << num[0] << ' ' << num[1] << ' ' << num[2] << endl;
            flag = true;
        }
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (!vis[i])
        {
            int n = (x - 1) / 3;
            int t = num[n];
            vis[i] = true;
            num[n] = 10 * num[n] + i;
            dfs(x + 1);
            vis[i] = false;
            num[n] = t;
        }
    }
}

int main()
{
    cin >> a >> b >> c;
    if (a && b && c)
        dfs(1);
    if (!flag)
        cout << "No!!!" << endl;
    return 0;
}