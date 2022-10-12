#include <bits/stdc++.h>

using namespace std;

struct Cood
{
    int x, y, z;
};

bool cmp(Cood a, Cood b)
{
    return a.z < b.z;
}

double dist(Cood a, Cood b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y) +
                (a.z - b.z) * (a.z - b.z));
}

int main()
{
    int N;
    cin >> N;
    vector<Cood> point(N);
    for (int i = 0; i < N; i++)
        cin >> point[i].x >> point[i].y >> point[i].z;
    sort(point.begin(), point.end(), cmp);
    double ans = 0.0;
    for (int i = 1; i < N; i++)
        ans += dist(point[i], point[i - 1]);
    cout << fixed << setprecision(3) << ans << endl;
    return 0;
}