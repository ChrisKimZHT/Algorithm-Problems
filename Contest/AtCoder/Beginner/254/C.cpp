#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
int N, K;
int a[MAXN];
map<int, set<int>> mp;

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        mp[a[i]].insert(i);
    }
    sort(a, a + N);
    bool flag = true;
    for (int i = 0; i < N; i++)
    {
        bool flag2 = false;
        for (auto j : mp[a[i]])
        {
            if (abs(j - i) % K == 0)
            {
                mp[a[i]].erase(j);
                flag2 = true;
                break;
            }
        }
        if (!flag2)
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}