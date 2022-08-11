#include <bits/stdc++.h>

using namespace std;

const string END = "12345678x";
queue<string> que;
unordered_map<string, int> dist;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int bfs(string start)
{
    dist[start] = 0;
    que.push(start);
    while (!que.empty())
    {
        string now = que.front();
        que.pop();
        if (now == END)
            return dist[now];
        int pos = now.find('x');
        int x = pos / 3, y = pos % 3;
        for (int i = 0; i < 4; i++)
        {
            string nxt = now;
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(nxt[pos], nxt[a * 3 + b]);
                if (!dist.count(nxt))
                {
                    que.push(nxt);
                    dist[nxt] = dist[now] + 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    string ori, c;
    for (int i = 0; i < 9; i++)
    {
        cin >> c;
        ori += c;
    }
    cout << bfs(ori) << endl;
    return 0;
}