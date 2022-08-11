#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int que[MAXN];
int head = 0, tail = -1;

void push(int val)
{
    que[++tail] = val;
}

void pop()
{
    head++;
}

bool empty()
{
    return (head - tail == 1) ? true : false;
}

int query()
{
    return que[head];
}

int main()
{
    int M;
    cin >> M;
    while (M--)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            int x;
            cin >> x;
            push(x);
        }
        else if (op == "empty")
        {
            cout << (empty() ? "YES" : "NO") << endl;
        }
        else if (op == "pop")
        {
            pop();
        }
        else if (op == "query")
        {
            cout << query() << endl;
        }
    }
    return 0;
}