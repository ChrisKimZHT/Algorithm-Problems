#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100010; // 链表长度

int head, idx;            // 头指针、数组位数
int val[SIZE], nxt[SIZE]; // 链表数据、下一位指针

// 初始化静态链表
void init()
{
    head = -1;
    idx = 0;
}

// 头插元素
void push_front(int x)
{
    val[idx] = x;
    nxt[idx] = head;
    head = idx;
    idx++;
}

// 在第pos位元素后插入x（元素序号从0开始）
void insert(int pos, int x)
{
    val[idx] = x;
    nxt[idx] = nxt[pos];
    nxt[pos] = idx;
    idx++;
}

// 删除第pos位元素，不可删除节点0
void erase(int pos)
{
    nxt[pos] = nxt[nxt[pos]];
}

// 遍历输出
void print()
{
    for (int i = head; i != -1; i = nxt[i])
        cout << val[i] << ' ';
    cout << endl;
}

int main(void)
{
    init();
    push_front(1);
    push_front(3);
    push_front(6);
    push_front(101);
    insert(3, -10);
    print();
    return 0;
}