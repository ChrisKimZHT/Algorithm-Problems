#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int n, q;
int arr[MAXN];

int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    while (q--)
    {
        int k;
        cin >> k;
        int x = lower_bound(arr, arr + n, k) - arr, y = upper_bound(arr, arr + n, k) - arr;
        if (x == n || arr[x] != k)
            cout << "-1 -1" << endl;
        else
            cout << x << ' ' << y - 1 << endl;
    }
    return 0;
}