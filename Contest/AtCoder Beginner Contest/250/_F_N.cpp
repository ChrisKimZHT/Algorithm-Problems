#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1e5 + 10;
int N;
pair<int, int> points[SIZE];

inline long long areax2(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    return abs(1ll * (c.first - a.first) * (b.second - a.second) - 1ll * (b.first - a.first) * (c.second - a.second));
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> points[i].first >> points[i].second;
    long long ax8 = 0;
    for (int i = 1; i < N - 1; i++)
    {
        ax8 += areax2(points[0], points[i], points[i + 1]);
    }
    long long ans = INT64_MAX;
    long long bx2 = 0;
    int j = 1;
    for (int i = 0; i < N; i++)
    {
        while (bx2 * 4 < ax8)
        {
            bx2 += areax2(points[i], points[j], points[(j + 1) % N]);
            j = (j + 1) % N;
            ans = min(ans, abs(ax8 - 4 * bx2));
        }
        bx2 -= areax2(points[i], points[(i + 1) % N], points[j]);
        ans = min(ans, abs(ax8 - 4 * bx2));
    }
    cout << ans << endl;
    return 0;
}