#include <bits/stdc++.h>

using namespace std;

vector<int> add(vector<int> &a, vector<int> &b)
{
    if (a.size() < b.size())
        return add(b, a);
    vector<int> ans;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i];
        if (i < b.size())
            t += b[i];
        ans.push_back(t % 10);
        t = t > 9 ? 1 : 0;
    }
    if (t)
        ans.push_back(t);
    return ans;
}

int main()
{
    string sa, sb;
    cin >> sa >> sb;
    vector<int> a, b, c;
    for (int i = sa.size() - 1; i >= 0; i--)
        a.push_back(sa[i] - '0');
    for (int i = sb.size() - 1; i >= 0; i--)
        b.push_back(sb[i] - '0');
    c = add(a, b);
    for (int i = c.size() - 1; i >= 0; i--)
        cout << c[i];
    cout << endl;
    return 0;
}