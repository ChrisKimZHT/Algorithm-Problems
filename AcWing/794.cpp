#include <bits/stdc++.h>

using namespace std;

pair<vector<int>, int> div(vector<int> &a, int b)
{
    vector<int> ans;
    int t = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        t = t * 10 + a[i];
        ans.push_back(t / b);
        t %= b;
    }
    reverse(ans.begin(), ans.end());
    while (!ans.back() && ans.size() - 1)
        ans.pop_back();
    return {ans, t};
}

int main()
{
    string sa;
    int b;
    cin >> sa >> b;
    vector<int> a;
    for (int i = sa.size() - 1; i >= 0; i--)
        a.push_back(sa[i] - '0');
    auto ans = div(a, b);
    for (int i = ans.first.size() - 1; i >= 0; i--)
        cout << ans.first[i];
    cout << endl
         << ans.second << endl;
    return 0;
}