#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    if (a.size() != b.size())
        return a.size() > b.size();
    for (int i = a.size() - 1; i >= 0; i--)
        if (a[i] != b[i])
            return a[i] > b[i];
    return true;
}

vector<int> sub(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t = a[i] - t;
        if (i < b.size())
            t -= b[i];
        ans.push_back((t + 10) % 10);
        t = t < 0 ? 1 : 0;
    }
    while (!ans.back() && ans.size() - 1)
        ans.pop_back();
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
    if (cmp(a, b))
        c = sub(a, b);
    else
    {
        c = sub(b, a);
        cout << '-';
    }
    for (int i = c.size() - 1; i >= 0; i--)
        cout << c[i];
    cout << endl;
    return 0;
}