#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100010; // 链表长度

int idx, val[SIZE], nxt[SIZE], prv[SIZE]; // 数组位数、链表数据、下一位指针、上一位指针

// 初始化静态双向链表
void init()
{
    nxt[0] = 1;
    prv[1] = 0;
    idx = 2;
}

// 头插元素
void push_front(int x)
{
    val[idx] = x;
    nxt[idx] = nxt[0];
    prv[idx] = 0;
    prv[nxt[0]] = idx;
    nxt[0] = idx;
    idx++;
}

// 尾接元素
void push_back(int x)
{
    val[idx] = x;
    nxt[idx] = 1;
    prv[idx] = prv[1];
    nxt[prv[1]] = idx;
    prv[1] = idx;
    idx++;
}

// 在第pos位元素后插入x（元素序号从2开始）
void insert(int pos, int x)
{
    val[idx] = x;
    nxt[idx] = nxt[pos];
    prv[idx] = pos;
    prv[nxt[pos]] = idx;
    nxt[pos] = idx;
    idx++;
}

// 删除第pos位元素，不可删除节点0/1
void erase(int pos)
{
    nxt[prv[pos]] = nxt[pos];
    prv[nxt[pos]] = prv[pos];
}

// 遍历输出
void print()
{
    for (int i = nxt[0]; i != 1; i = nxt[i])
        cout << val[i] << ' ';
    cout << endl;
}

int main()
{
    init();
    push_back(2);
    print();
    push_front(1);
    print();
    push_front(4);
    print();
    insert(3,5);
    print();
    push_back(6);
    print();
    erase(3);
    print();
    return 0;
}