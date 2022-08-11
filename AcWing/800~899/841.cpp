#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10, AWA = 131;
int n, m;
char str[MAXN];
unsigned long long hs[MAXN], p[MAXN];

void init()
{
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * AWA;
        hs[i] = hs[i - 1] * AWA + str[i];
    }
}

unsigned long long geths(int l, int r)
{
    return hs[r] - hs[l - 1] * p[r - l + 1];
}

int main()
{
    cin >> n >> m;
    cin >> str + 1;
    init();
    while (m--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (geths(l1, r1) == geths(l2, r2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}