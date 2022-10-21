#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
int N, p[MAXN];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> p[i];
    map<int, int> mp;
    for (int i = 0; i < N; i++)
    {
        mp[(p[i] - i - 1 + N) % N]++;
        mp[(p[i] - i + N) % N]++;
        mp[(p[i] - i + 1 + N) % N]++;
    }
    int mx = 0;
    for (auto par : mp)
        mx = max(mx, par.second);
    cout << mx << endl;
    return 0;
}