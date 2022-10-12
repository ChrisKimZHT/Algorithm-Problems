#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;
int N, a[MAXN];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]), ans++;
    cout << ans << endl;
    return 0;
}