//
// Created by ChrisKim on 2022/10/25.
//

#ifndef EXPERIMENT_DSA_01_LINK_LIST_H
#define EXPERIMENT_DSA_01_LINK_LIST_H

#include <iostream>

template<typename T>
class LinkListNode
{
public:
    T data;
    LinkListNode<T> *next;
};

template<typename T>
class LinkList : public LinkListNode<T>
{
private:
    int size{};
    LinkListNode<T> *head{};
public:
    LinkList()
    {
        this->head = new LinkListNode<T>;
        this->size = 0;
        this->head->next = nullptr;
    }
    ~LinkList()
    {
        clearList();
    }
    LinkList(const LinkList<T> &original)
    {
        for (auto *pos = original->head; pos != nullptr; pos = pos->next)
        {
            pushBack(pos->data);
        }
    }
    int getSize()
    {
        return this->size;
    }
    void pushFront(T data)
    {
        auto *new_node = new LinkListNode<T>;
        new_node->data = data;
        new_node->next = this->head->next;
        this->head->next = new_node;
        this->size++;
    }
    void pushBack(T data)
    {
        auto *new_node = new LinkListNode<T>;
        new_node->data = data;
        new_node->next = nullptr;
        auto *tail = this->head;
        for (int i = 0; i < this->size; i++)
            tail = tail->next;
        tail->next = new_node;
        this->size++;
    }
    bool insertElement(int idx, T data)
    {
        if (!(0 <= idx && idx < size))
            return false;
        auto *pos = this->head;
        for (int i = 0; i <= idx; i++)
            pos = pos->next;
        auto *new_node = new LinkListNode<T>;
        new_node->data = data;
        new_node->next = pos->next;
        pos->next = new_node;
        this->size++;
        return true;
    }
    bool deleteElement(int idx)
    {
        if (!(0 <= idx && idx < size))
            return false;
        auto *pos = this->head;
        for (int i = 0; i < idx; i++)
            pos = pos->next;
        LinkListNode<T> *del = pos->next;
        pos->next = del->next;
        delete del;
        this->size--;
        return true;
    }
    void displayList()
    {
        std::cout << '[';
        bool flag = false;
        for (auto *pos = this->head; pos != nullptr; pos = pos->next)
        {
            if (flag)
                std::cout << ", ";
            flag = true;
            std::cout << pos->data;
        }
        std::cout << ']' << std::endl;
    }
    void clearList()
    {
        LinkListNode<T> *del = nullptr;
        while (head->next != nullptr)
        {
            del = head->next;
            head->next = del->next;
            delete del;
        }
        this->size = 0;
    }
    T &operator[](int idx)
    {
        auto *pos = this->head;
        for (int i = 0; i <= idx; i++)
            pos = pos->next;
        return pos->data;
    }
};

#endif //EXPERIMENT_DSA_01_LINK_LIST_H
