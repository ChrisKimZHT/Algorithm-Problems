//
// Created by ChrisKim on 2022/10/23.
//

#ifndef EXPERIMENT_DSA_01_SEQ_LIST_H
#define EXPERIMENT_DSA_01_SEQ_LIST_H

#include <iostream>

const int DEFAULT_CAPACITY = 8;

template<typename T>
class SeqList
{
private:
    T *data;
    int size;
    int capacity;
    void resizeList()
    {
        T *new_data = new T[capacity * 2];
        for (int i = 0; i < this->size; i++)
            new_data[i] = data[i];
        delete data;
        data = new_data;
        capacity *= 2;
    }

public:
    SeqList()
    {
        data = new T[DEFAULT_CAPACITY];
        size = 0;
        capacity = DEFAULT_CAPACITY;
    }
    ~SeqList()
    {
        delete[] data;
    }
    SeqList(const SeqList<T> &original)
    {
        data = new T[original.capacity];
        size = original.size;
        capacity = original.capacity;
        for (int i = 0; i < size; i++)
            data[i] = original.data[i];
    }
    void createList(T arr[], int len)
    {
        while (capacity < len)
            resizeList();
        for (int i = 0; i < len; i++)
            data[i] = arr[i];
    }
    void clearList()
    {
        size = 0;
    }
    bool getFront(T &element)
    {
        if (size)
        {
            element = data[0];
            return true;
        }
        return false;
    }
    bool getBack(T &element)
    {
        if (size)
        {
            element = data[size - 1];
            return true;
        }
        return false;
    }
    int getSize()
    {
        return size;
    }
    void pushBack(T element)
    {
        if (size == capacity)
            resizeList();
        data[size++] = element;
    }
    void popBack()
    {
        size--;
    }
    bool getElement(T &element, int idx)
    {
        if (0 <= idx && idx < size)
        {
            element = data[idx];
            return true;
        }
        return false;
    }
    bool setElement(T element, int idx)
    {
        if (0 <= idx && idx < size)
        {
            data[idx] = element;
            return true;
        }
        return false;
    }
    bool insertElement(T element, int idx)
    {
        if (!(0 <= idx && idx < size))
            return false;
        if (size == capacity)
            resizeList();
        for (int i = size - 1; i >= idx; i--)
            data[i + 1] = data[i];
        data[idx] = element;
        size++;
        return true;
    }
    bool deleteElement(int idx)
    {
        if (!(0 <= idx && idx < size - 1))
            return false;
        for (int i = idx; i < size - 1; i++)
            data[i] = data[i + 1];
        size--;
        return true;
    }
    int findElement(T element)
    {
        for (int i = 0; i < size; i++)
            if (element == data[i])
                return i;
        return size;
    }
    void displayList()
    {
        std::cout << '[';
        for (int i = 0; i < size; i++)
        {
            if (i)
                std::cout << ", ";
            std::cout << data[i];
        }
        std::cout << ']' << std::endl;
    }
    T &operator[](int idx)
    {
        return data[idx];
    }
};


#endif //EXPERIMENT_DSA_01_SEQ_LIST_H