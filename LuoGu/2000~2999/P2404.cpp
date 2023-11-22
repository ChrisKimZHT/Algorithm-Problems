#include <bits/stdc++.h>

using namespace std;

vector<int> num;
void dfs(int x, int l)
{
    if (!x)
    {
        if (num.size() > 1)
        {
            for (int i = 0; i < num.size(); i++)
            {
                if (i)
                    cout << '+';
                cout << num[i];
            }
            cout << endl;
        }
        return;
    }
    for (int i = l; i <= 8; i++)
    {
        if (x - i >= 0)
        {
            num.push_back(i);
            dfs(x - i, i);
            num.pop_back();
        }
    }
}

int main()
{
    int n;
    cin >> n;
    dfs(n, 1);
    return 0;
}