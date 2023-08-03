//
// Created by ChrisKim on 2022/10/25.
//

#ifndef EXPERIMENT_DSA_02_SEQ_STACK_H
#define EXPERIMENT_DSA_02_SEQ_STACK_H

const int MAX_SIZE = 1024;

template<typename T>
class SeqStack
{
private:
    T *data;
    int idx;
public:
    SeqStack()
    {
        data = new T[MAX_SIZE];
        idx = -1;
    }
    ~SeqStack()
    {
        delete[] data;
    }
    bool empty()
    {
        return idx == -1;
    }
    int size()
    {
        return idx + 1;
    }
    void clear()
    {
        idx = -1;
    }
    void push(T element)
    {
        data[++idx] = element;
    }
    void pop()
    {
        idx--;
    }
    T top()
    {
        return data[idx];
    }
};


#endif //EXPERIMENT_DSA_02_SEQ_STACK_H
