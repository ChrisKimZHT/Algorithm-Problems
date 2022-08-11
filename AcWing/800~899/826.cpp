#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100010;    // 链表长度
int head, idx;              // head头指针，idx储存数组当前使用了多少位（便于添加新数据
int value[SIZE], nxt[SIZE]; // value数据域，nxt指针域
void init()
{
    head = -1;
    idx = 0;
}

void push_front(int x)
{
    value[idx] = x;
    nxt[idx] = head;
    head = idx;
    idx++;
}

void array_insert(int pos, int x)
{
    value[idx] = x;
    nxt[idx] = nxt[pos];
    nxt[pos] = idx;
    idx++;
}

void erase(int pos)
{
    nxt[pos] = nxt[nxt[pos]];
}

void print()
{
    for (int i = head; i != -1; i = nxt[i])
        cout << value[i] << ' ';
    cout << endl;
}

int main()
{
    init();
    int M;
    cin >> M;
    while (M--)
    {
        char oper;
        cin >> oper;
        if (oper == 'H')
        {
            int x;
            cin >> x;
            push_front(x);
        }
        else if (oper == 'D')
        {
            int k;
            cin >> k;
            if (!k)
                head = nxt[head];
            erase(k - 1);
        }
        else
        {
            int k, x;
            cin >> k >> x;
            array_insert(k - 1, x);
        }
    }
    print();
    return 0;
}