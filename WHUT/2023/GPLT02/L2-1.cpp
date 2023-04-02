#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 10;
int e[MAXN], ne[MAXN];
bool st[MAXN];

string parse_addr(int x)
{
    if (x == -1)
        return "-1";
    string addr = to_string(x);
    string pre;
    for (int i = 0; i < 5 - addr.size(); i++)
        pre += '0';
    return pre + addr;
}

void solve()
{
    int head, cnt;
    cin >> head >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        int addr, val, nxt;
        cin >> addr >> val >> nxt;
        e[addr] = val;
        ne[addr] = nxt;
    }
    int last = -1;
    int removed_head = -1, removed_last = -1;
    for (int i = head; i != -1; i = ne[i])
    {
        if (!st[abs(e[i])])
        {
            st[abs(e[i])] = true;
            last = i;
        }
        else
        {
            if (removed_head == -1)
                removed_head = i;
            else
                ne[removed_last] = i;
            removed_last = i;
            ne[last] = ne[i];
        }
    }
    if (removed_last != -1)
        ne[removed_last] = -1;
    for (int i = head; i != -1; i = ne[i])
        cout << parse_addr(i) + ' ' + to_string(e[i]) + ' ' + parse_addr(ne[i]) << endl;
    for (int i = removed_head; i != -1; i = ne[i])
        cout << parse_addr(i) + ' ' + to_string(e[i]) + ' ' + parse_addr(ne[i]) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}