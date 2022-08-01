#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100010;
int st[SIZE], idx = 0;

void push(int val)
{
    st[idx++] = val;
}

void pop()
{
    idx--;
}

int query()
{
    return st[idx - 1];
}

bool empty()
{
    return (idx ? false : true);
}

int main()
{
    int M;
    cin >> M;
    while (M--)
    {
        string oper;
        cin >> oper;
        if (oper == "push")
        {
            int x;
            cin >> x;
            push(x);
        }
        else if (oper == "pop")
        {
            pop();
        }
        else if (oper == "query")
        {
            cout << query() << endl;
        }
        else if (oper == "empty")
        {
            cout << (empty() ? "YES" : "NO") << endl;
        }
    }
    return 0;
}