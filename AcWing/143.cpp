#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4e6;
int son[MAXN][2], idx;
int N, A[MAXN];

void insert(int num)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int c = num >> i & 1;
        if (!son[p][c])
            son[p][c] = ++idx;
        p = son[p][c];
    }
}

int search(int num)
{
    int p = 0, ans = 0;
    for (int i = 30; i >= 0; i--)
    {
        int c = num >> i & 1;
        if (son[p][!c])
        {
            p = son[p][!c];
            ans = ans * 2 + 1;
        }
        else
        {
            p = son[p][c];
            ans = ans * 2;
        }
    }
    return ans;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        insert(A[i]);
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = max(ans, search(A[i]));
    cout << ans << endl;
    return 0;
}