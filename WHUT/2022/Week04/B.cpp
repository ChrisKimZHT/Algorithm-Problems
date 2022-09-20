#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 50;
pair<int, int> p[MAXN];
int N;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return 1.0 * a.first / a.second > 1.0 * b.first / b.second;
}

int main()
{
    while (cin >> N)
    {
        for (int i = 0; i < N; i++)
            cin >> p[i].first >> p[i].second;
        sort(p, p + N, cmp);
        int ans = 0, t = 0;
        for (int i = 0; i < N; i++)
        {
            t += p[i].second;
            ans += t * p[i].first;
        }
        cout << ans << endl;
    }
    return 0;
}