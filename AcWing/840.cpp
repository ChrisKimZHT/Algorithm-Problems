#include <bits/stdc++.h>

using namespace std;

// 开放寻址法
const int SIZE = 200003, NONE = 0x3f3f3f3f;
int hs[SIZE];
int N;

inline int f(int x)
{
    return (x % SIZE + SIZE) % SIZE;
}

int find(int x)
{
    int y = f(x);
    while (hs[y] != NONE && hs[y] != x)
    {
        y++;
        if (y == SIZE)
            y = 0;
    }
    return y;
}

void insert(int x)
{
    int k = find(x);
    hs[k] = x;
}

bool query(int x)
{
    int k = find(x);
    return hs[k] == x;
}

// 拉链法
/* const int SIZE = 100003;
int hs[SIZE], val[SIZE], nxt[SIZE], idx;
int N;

inline int f(int x)
{
    return (x % SIZE + SIZE) % SIZE;
}

void insert(int x)
{
    int y = f(x);
    val[idx] = x;
    nxt[idx] = hs[y];
    hs[y] = idx++;
}

bool query(int x)
{
    int y = f(x);
    for (int i = hs[y]; i != -1; i = nxt[i])
        if (val[i] == x)
            return true;
    return false;
} */

int main()
{
    memset(hs, 0x3f, sizeof(hs));
    // memset(hs, -1, sizeof(hs));
    cin >> N;
    while (N--)
    {
        char op;
        int x;
        cin >> op >> x;
        if (op == 'I')
            insert(x);
        else
            cout << (query(x) ? "Yes" : "No") << endl;
    }
    return 0;
}