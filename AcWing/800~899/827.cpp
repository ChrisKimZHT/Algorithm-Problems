#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100010;

int idx, val[SIZE], nxt[SIZE], prv[SIZE];

void init()
{
    nxt[0] = 1;
    prv[1] = 0;
    idx = 2;
}
void push_front(int x)
{
    val[idx] = x;
    nxt[idx] = nxt[0];
    prv[idx] = 0;
    prv[nxt[0]] = idx;
    nxt[0] = idx;
    idx++;
}

void push_back(int x)
{
    val[idx] = x;
    nxt[idx] = 1;
    prv[idx] = prv[1];
    nxt[prv[1]] = idx;
    prv[1] = idx;
    idx++;
}
void insert(int pos, int x)
{
    val[idx] = x;
    nxt[idx] = nxt[pos];
    prv[idx] = pos;
    prv[nxt[pos]] = idx;
    nxt[pos] = idx;
    idx++;
}

void erase(int pos)
{
    nxt[prv[pos]] = nxt[pos];
    prv[nxt[pos]] = prv[pos];
}

void print()
{
    for (int i = nxt[0]; i != 1; i = nxt[i])
        cout << val[i] << ' ';
    cout << endl;
}

int main()
{
    init();
    int M;
    cin >> M;
    while (M--)
    {
        char op;
        cin >> op;
        if (op == 'L')
        {
            int x;
            cin >> x;
            push_front(x);
        }
        else if (op == 'R')
        {
            int x;
            cin >> x;
            push_back(x);
        }
        else if (op == 'D')
        {
            int k;
            cin >> k;
            erase(k + 1);
        }
        else if (op == 'I')
        {
            int k, x;
            cin >> op >> k >> x;
            if (op == 'L')
                insert(prv[k + 1], x);
            else
                insert(k + 1, x);
        }
    }
    print();
    return 0;
}