#include <bits/stdc++.h>

using namespace std;

struct NODE
{
    int value;
    NODE *next;
};

NODE *head;
void init()
{
    head = new NODE;
    head->next = NULL;
}

void push_front(int x)
{
    NODE *node = new NODE;
    node->value = x;
    node->next = head->next;
    head->next = node;
}

void push_back(int x)
{
    NODE *node = new NODE;
    node->value = x;
    node->next = NULL;
    NODE *p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = node;
}

void print()
{
    for (NODE *p = head->next; p != NULL; p = p->next)
        cout << p->value << ' ';
    cout << endl;
}

void insert(int id, int x)
{
    NODE *tmp = head;
    for (int i = 0; i <= id; i++)
        tmp = tmp->next;
    NODE *node = new NODE;
    node->value = x;
    node->next = tmp->next;
    tmp->next = node;
}

void erase(int id)
{
    NODE *tmp = head;
    for (int i = 0; i < id; i++)
        tmp = tmp->next;
    NODE *del = tmp->next;
    tmp->next = del->next;
    delete del;
}

int main(void)
{
    init();
    push_back(1);
    print();
    print();

    return 0;
}