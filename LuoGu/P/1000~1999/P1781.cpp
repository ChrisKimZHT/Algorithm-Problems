#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return a[i] < b[i];
    return true;
}

int main()
{
    int n;
    cin >> n;
    int m;
    string ans;
    for (int i = 1; i <= n; i++)
    {
        string tmp;
        cin >> tmp;
        if (cmp(ans, tmp))
        {
            ans = tmp;
            m = i;
        }
    }
    cout << m << endl
         << ans << endl;
    return 0;
}