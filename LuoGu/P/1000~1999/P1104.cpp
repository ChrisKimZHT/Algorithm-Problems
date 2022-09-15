#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<string, long long> a, pair<string, long long> b)
{
    return a.second <= b.second;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<string, long long>> stu;
    while (n--)
    {
        string s;
        long long a, b, c;
        cin >> s >> a >> b >> c;
        long long t = a * 1e6 + b * 1e4 + c * 1e2 + n;
        stu.push_back({s, t});
    }
    sort(stu.begin(), stu.end(), cmp);
    for (auto p : stu)
        cout << p.first << endl;
    return 0;
}