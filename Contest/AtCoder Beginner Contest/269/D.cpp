#include <bits/stdc++.h>

using namespace std;

int dx[6] = {-1, -1, 0, 0, 1, 1};
int dy[6] = {-1, 0, -1, 1, 0, 1};

int main()
{
    int N;
    cin >> N;
    set<pair<int, int>> dot;
    while (N--)
    {
        int X, Y;
        cin >> X >> Y;
        dot.insert({X, Y});
    }
    N = dot.size();
    int ans = 0;
    while (dot.size())
    {
        queue<pair<int, int>> que;
        pair<int, int> x = *dot.begin();
        dot.erase(x);
        que.push(x);
        while (que.size())
        {
            pair<int, int> d = que.front();
            que.pop();
            for (int i = 0; i < 6; i++)
            {
                pair<int, int> nd = {d.first + dx[i], d.second + dy[i]};
                if (dot.find(nd) != dot.end())
                {
                    que.push(nd);
                    dot.erase(nd);
                }
            }
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}