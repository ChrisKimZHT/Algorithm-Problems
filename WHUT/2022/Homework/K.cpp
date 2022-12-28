#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

string trans(int a, int b)
{
    vector<int> va, vb;
    if (a == 0)
        va.push_back(0);
    if (b == 0)
        vb.push_back(0);
    while (a)
    {
        va.push_back(a % 10);
        a /= 10;
    }
    while (b)
    {
        vb.push_back(b % 10);
        b /= 10;
    }
    for (int i = 0; i < vb.size(); i++)
    {
        for (int j = 0; j < va.size(); j++)
        {
            if (vb[i] == va[j] && vb[i] != -1)
            {
                vb[i] = va[j] = -1;
                break;
            }
        }
    }
    string sa, sb;
    for (int i = va.size() - 1; i >= 0; i--)
        if (va[i] != -1)
            sa += char('0' + va[i]);
    for (int i = vb.size() - 1; i >= 0; i--)
        if (vb[i] != -1)
            sb += char('0' + vb[i]);
    return sa + '/' + sb;
}

const double eps = 1e-7;

bool cmp(pair<pair<int, int>, string> a, pair<pair<int, int>, string> b)
{
    double xya = 1.0 * a.first.first / a.first.second, xyb = 1.0 * b.first.first / b.first.second;
    if (fabs(xya - xyb) < eps)
        return a.first.first < b.first.first;
    return xya < xyb;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int L1, R1, L2, R2;
    cin >> L1 >> R1 >> L2 >> R2;
    vector<pair<pair<int, int>, string>> ans;
    for (int i = L1; i <= R1; i++)
    {
        for (int j = L2; j <= R2; j++)
        {
            int x = i / __gcd(i, j), y = j / __gcd(i, j);
            string xy = to_string(x) + '/' + to_string(y);
            string ab = trans(i, j);
            if (xy == ab)
            {
                ans.push_back({{i, j}, xy});
            }
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size() << endl;
    for (auto &ele : ans)
    {
        cout << ele.first.first << '/' << ele.first.second << '=' << ele.second << endl;
    }
    return 0;
}