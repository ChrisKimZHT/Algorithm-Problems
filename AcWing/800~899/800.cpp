#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int n, m, x;
int A[MAXN], B[MAXN];

int main()
{
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
        cin >> B[i];
    int a = 0, b = m - 1;
    while (true)
    {
        if (A[a] + B[b] > x && b >= 0)
            b--;
        else if (A[a] + B[b] < x && a < n)
            a++;
        if (A[a] + B[b] == x)
            break;
    }
    cout << a << ' ' << b << endl;
    return 0;
}