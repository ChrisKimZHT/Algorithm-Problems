#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;
int n, m;
int a[MAXN];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (m--)
        next_permutation(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << ' ';
        cout << a[i];
    }
    cout << endl;
    return 0;
}