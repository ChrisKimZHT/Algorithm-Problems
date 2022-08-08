#include <bits/stdc++.h>

using namespace std;

vector<int> mul(vector<int> a, int b)
{
    vector<int> ans;
    if (!b)
    {
        ans.push_back(0);
        return ans;
    }
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i] * b;
        ans.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        ans.push_back(t % 10);
        t /= 10;
    }
    return ans;
}

int main()
{
    string sa;
    int b;
    cin >> sa >> b;
    vector<int> a, c;
    for (int i = sa.size() - 1; i >= 0; i--)
        a.push_back(sa[i] - '0');
    c = mul(a, b);
    for (int i = c.size() - 1; i >= 0; i--)
        cout << c[i];
    cout << endl;
    return 0;
}