//
// Created by ChrisKim on 2022/10/26.
//

#ifndef EXPERIMENT_DSA_02_LIST_STACK_H
#define EXPERIMENT_DSA_02_LIST_STACK_H

template<typename T>
class LinkStackNode
{
public:
    T data;
    LinkStackNode<T> *next;
};

template<typename T>
class ListStack : public LinkStackNode<T>
{
private:
    int stackSize{};
    LinkStackNode<T> *head{};
public:
    ListStack()
    {
        head = new LinkStackNode<T>;
        stackSize = 0;
        head->next = nullptr;
    }
    ~ListStack()
    {
        clear();
    }
    int size()
    {
        return stackSize;
    }
    void push(T data)
    {
        auto *new_node = new LinkStackNode<T>;
        new_node->data = data;
        new_node->next = head->next;
        head->next = new_node;
        stackSize++;
    }
    T top()
    {
        return head->next->data;
    }
    void pop()
    {
        auto *del = head->next;
        head->next = del->next;
        delete del;
        stackSize--;
    }
    void clear()
    {
        LinkStackNode<T> *del = nullptr;
        while (head->next != nullptr)
        {
            del = head->next;
            head->next = del->next;
            delete del;
        }
        stackSize = 0;
    }
};


#endif //EXPERIMENT_DSA_02_LIST_STACK_H
