#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
int son[MAXN][26], cnt[MAXN], idx;

void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int c = str[i] - 'a';
        if (!son[p][c])
            son[p][c] = ++idx;
        p = son[p][c];
    }
    cnt[p]++;
}

int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int c = str[i] - 'a';
        if (!son[p][c])
            return 0;
        p = son[p][c];
    }
    return cnt[p];
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char str[MAXN];
        cin >> str;
        insert(str);
    }
    int m;
    cin >> m;
    while (m--)
    {
        char str[MAXN];
        cin >> str;
        cout << query(str) << endl;
    }
    return 0;
}