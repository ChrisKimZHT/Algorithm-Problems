#include <bits/stdc++.h>

using namespace std;

int main()
{
    deque<pair<int, int>> dque;
    int Q;
    cin >> Q;
    while (Q--)
    {
        int operation;
        cin >> operation;
        if (operation == 1)
        {
            int x, c;
            cin >> x >> c;
            dque.push_back({c, x});
        }
        else
        {
            int c;
            cin >> c;
            long long ans = 0;
            while (c)
            {
                auto front = dque.front();
                dque.pop_front();
                if (c >= front.first)
                {
                    c -= front.first;
                    ans += (long long)front.first * front.second;
                }
                else
                {
                    ans += (long long)c * front.second;
                    dque.push_front({front.first - c, front.second});
                    c = 0;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}