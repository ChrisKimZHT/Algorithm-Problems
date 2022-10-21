#include <iostream>

using namespace std;

int n;
int mp[110][110]; // 前一个为行, 后一个为列

int peacnt(int x, int y)
{
    // 左
    int ans = 0;
    int cnt = 0;
    for (int i = x; i >= 0; i--)
    {
        if (cnt + mp[y][i] >= 0)
            cnt += mp[y][i];
        else
            cnt = 0;
    }
    // 下
    ans = max(cnt, ans);
    cnt = 0;
    for (int i = y; i < n; i++)
    {
        if (cnt + mp[i][x] >= 0)
            cnt += mp[i][x];
        else
            cnt = 0;
    }
    // 上
    ans = max(cnt, ans);
    cnt = 0;
    for (int i = y; i >= 0; i--)
    {
        if (cnt + mp[i][x] >= 0)
            cnt += mp[i][x];
        else
            cnt = 0;
    }
    // 右
    ans = max(cnt, ans);
    cnt = 0;
    for (int i = x; i < n; i++)
    {
        if (cnt + mp[y][i] >= 0)
            cnt += mp[y][i];
        else
            cnt = 0;
    }
    // 左下
    ans = max(cnt, ans);
    cnt = 0;
    for (int i = x, j = y; i >= 0 && j < n; i--, j++)
    {
        if (cnt + mp[j][i] >= 0)
            cnt += mp[j][i];
        else
            cnt = 0;
    }
    // 左上
    ans = max(cnt, ans);
    cnt = 0;
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
    {
        if (cnt + mp[j][i] >= 0)
            cnt += mp[j][i];
        else
            cnt = 0;
    }
    // 右下
    ans = max(cnt, ans);
    cnt = 0;
    for (int i = x, j = y; i < n && j < n; i++, j++)
    {
        if (cnt + mp[j][i] >= 0)
            cnt += mp[j][i];
        else
            cnt = 0;
    }
    // 右上
    ans = max(cnt, ans);
    cnt = 0;
    for (int i = x, j = y; i < n && j >= 0; i++, j--)
    {
        if (cnt + mp[j][i] >= 0)
            cnt += mp[j][i];
        else
            cnt = 0;
    }
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mp[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        a = peacnt(i, 0);
        b = peacnt(i, n - 1);
        c = peacnt(0, i);
        d = peacnt(n - 1, i);
        ans = max(ans, max(max(a, b), max(c, d)));
    }
    cout << ans << endl;
    return 0;
}