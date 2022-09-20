#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

int main()
{
    int n;
    while (cin >> n, n)
    {
        vector<PII> prog(n);
        for (int i = 0; i < n; i++)
            cin >> prog[i].first >> prog[i].second;
        sort(prog.begin(), prog.end());
        int cnt = 0, now = 0;
        for (int i = 0; i < prog.size(); i++)
        {
            if (prog[i].first >= now)
            {
                cnt++;
                now = prog[i].second;
            }
            else if (prog[i].second < now)
            {
                now = prog[i].second;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}