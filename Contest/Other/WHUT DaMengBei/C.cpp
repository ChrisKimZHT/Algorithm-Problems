#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string S, T;
    cin >> S >> T;
    vector<string> ans;
    string tmp;
    for (int i = 0; i < n; i++)
    {
        if (T[i] == 'A' || T[i] == 'C' || T[i] == 'M')
        {
            tmp += S[i];
        }
        else
        {
            if (tmp.size())
            {
                ans.push_back(tmp);
                tmp.clear();
            }
        }
    }
    if (tmp.size())
    {
        ans.push_back(tmp);
        tmp.clear();
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}