#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> cses;
vector<int> cse;

void dfs(int rem)
{
    if (cse.size() > 10)
        return;
    if (rem == 0 && cse.size() == 10)
        cses.push_back(cse);
    for (int i = 1; i <= 3; i++)
    {
        if (rem >= i)
        {
            cse.push_back(i);
            dfs(rem - i);
            cse.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    dfs(n);
    cout << cses.size() << endl;
    for (auto &c : cses)
    {
        for (auto &i : c)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}