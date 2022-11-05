#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    set<int> ed[N + 1];
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        ed[a].insert(b);
        ed[b].insert(a);
    }
    for (int i = 1; i <= N; i++)
    {
        cout << ed[i].size() << ' ';
        for (auto n : ed[i])
            cout << n << ' ';
        cout << endl;
    }
    return 0;
}