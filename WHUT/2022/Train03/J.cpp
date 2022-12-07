#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 100;
int n, a[MAXN];
int fact[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    for (int i = 1; i <= 20; i++)
        fact[i] = fact[i - 1] * i;
    cin >> n;
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    for (int i = 0; i < fact[n]; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[j] << ' ';
        cout << endl;
        next_permutation(a, a + n);
    }
    return 0;
}