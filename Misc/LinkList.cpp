#include <iostream>

using namespace std;

template <typename T>
class linklist_node
{
public:
    T data;
    linklist_node<T> *next;
};

template <typename T>
class linklist : public linklist_node<T>
{
private:
    linklist_node<int> *head{};

public:
    linklist();
    bool empty();
    int size();
    void push_front(T);
    void push_back(T);
    void insert(int, T);
    void erase(int);
    void print();
    T &operator[](int);
};

template <typename T>
linklist<T>::linklist()
{
    this->head = new linklist_node<T>;
    this->head->data = 0;
    this->head->next = nullptr;
}

template <typename T>
bool linklist<T>::empty()
{
    if (this->head->next == nullptr)
        return true;
    else
        return false;
}

template <typename T>
int linklist<T>::size()
{
    return this->head->data;
}

template <typename T>
void linklist<T>::push_front(T data)
{
    auto *new_node = new linklist_node<T>;
    new_node->data = data;
    new_node->next = this->head->next;
    this->head->next = new_node;
    this->head->data++;
}

template <typename T>
void linklist<T>::push_back(T data)
{
    auto *new_node = new linklist_node<T>;
    new_node->data = data;
    new_node->next = nullptr;
    auto *tail = this->head;
    for (int i = 0; i < this->size(); i++)
        tail = tail->next;
    tail->next = new_node;
    this->head->data++;
}

template <typename T>
void linklist<T>::insert(int idx, T data)
{
    auto *pos = this->head;
    for (int i = 0; i <= idx; i++)
        pos = pos->next;
    auto *new_node = new linklist_node<T>;
    new_node->data = data;
    new_node->next = pos->next;
    pos->next = new_node;
    this->head->data++;
}

template <typename T>
void linklist<T>::erase(int idx)
{
    auto *pos = this->head;
    for (int i = 0; i < idx; i++)
        pos = pos->next;
    linklist_node<T> *del = pos->next;
    pos->next = del->next;
    delete del;
    this->head->data--;
}

template <typename T>
void linklist<T>::print()
{
    for (auto p = this->head->next; p != nullptr; p = p->next)
        cout << p->data << ' ';
    cout << endl;
}

template <typename T>
T &linklist<T>::operator[](int idx)
{
    auto *pos = this->head;
    for (int i = 0; i <= idx; i++)
        pos = pos->next;
    return pos->data;
}

int main()
{
    linklist<int> my_linklist;
    my_linklist.push_front(0);
    my_linklist.print();
    my_linklist.push_front(1);
    my_linklist.print();
    my_linklist.push_front(2);
    my_linklist.print();
    my_linklist.push_back(3);
    my_linklist.print();
    my_linklist.push_back(4);
    my_linklist.print();
    my_linklist.insert(0, 100);
    my_linklist.print();
    my_linklist.insert(3, 101);
    my_linklist.print();
    my_linklist.insert(5, 102);
    my_linklist.print();
    my_linklist.erase(0);
    my_linklist.print();
    my_linklist.erase(2);
    my_linklist.print();
    my_linklist.erase(5);
    my_linklist.print();
    return 0;
}

// #include <iostream>
// using namespace std;
// template <typename T>
// class Node
// {
// public:
//     /* 用于链表节点的定义 */
//     T data;        // 表示数据域
//     Node<T> *next; // 表示指针域，存储下一个节点的位置
// };
// template <typename T>
// class LinkList : public Node<T>
// {
// private:
//     /* 用于链表的定义 */
//     Node<T> *head; // 头节点
// public:
//     /* 成员函数的声明 */
//     LinkList();                              // 重写默认的构造函数
//     bool Empty();                            // 判断链表是否为空
//     int GetLen();                            // 获取链表的长度
//     void insert(T elem);                     // 默认插入链表的开头
//     bool insert(int idx, T elem);            // 在链表的指定位置插入元素
//     void remove(T &elem);                    // 默认删除链表的第一个元素，并返回该元素
//     bool remove(int idx, T &elem);           // 删除并指定位置的元素
//     bool index(int idx, T &elem);            // 找出并返回指定位置的元素
//     int index(bool(*compare(T, T)), T elem); // 找到并返回满足compare的元素
//     void traverse(void (*print)(T &elem));   // 用于遍历整个链表
// };

// /* 用于实现成员函数的定义 */
// template <typename T>
// inline LinkList<T>::LinkList()
// {
//     this->head = (Node<T> *)malloc(sizeof(Node<T>));
//     if (!this->head)
//     {
//         cerr << "Error allocating memory!" << endl;
//     }
//     this->head->next = nullptr;
// }

// template <typename T>
// inline bool LinkList<T>::Empty()
// {
//     if (this->head == nullptr)
//     {
//         return true;
//     }
//     return false;
// }

// template <typename T>
// int LinkList<T>::GetLen()
// {
//     Node<T> *tmp = this->head->next;
//     int counter = 0;
//     while (tmp)
//     {
//         counter++;
//         tmp = tmp->next;
//     }
//     return counter;
// }

// template <typename T>
// inline void LinkList<T>::insert(T elem)
// {
//     Node<T> *newnode = (Node<T> *)malloc(sizeof(Node<T>));
//     newnode->data = elem;
//     newnode->next = this->head->next;
//     this->head->next = newnode;
// }

// template <typename T>
// bool LinkList<T>::insert(int idx, T elem)
// {
//     if (idx < 1 || idx > this->GetLen() + 1)
//     {
//         cerr << "subscript wrong!" << endl;
//         return false;
//     }
//     int counter = 0;
//     Node<T> *newnode = this->head, *tmp = (Node<T> *)malloc(sizeof(Node<T>));
//     while (counter < idx - 1 && newnode->next != nullptr)
//     {
//         counter++;
//         newnode = newnode->next;
//     }
//     tmp->data = elem;
//     tmp->next = newnode->next;
//     newnode->next = tmp;
//     return true;
// }

// template <typename T>
// void LinkList<T>::remove(T &elem)
// {
//     Node<T> *tmp = this->head->next;
//     this->head->next = tmp->next;
//     elem = tmp->data;
//     free(tmp);
// }

// template <typename T>
// bool LinkList<T>::remove(int idx, T &elem)
// {
//     if (idx < 1 || idx > this->GetLen())
//     {
//         cerr << "subscript wrong!" << endl;
//         return false;
//     }
//     Node<T> *newnode = this->head, *tmp;
//     int counter = 0;
//     while (counter < idx - 1 && newnode->next != nullptr)
//     {
//         newnode = newnode->next;
//         counter++;
//     }
//     tmp = newnode->next;
//     elem = tmp->data;
//     newnode->next = tmp->next;
//     free(tmp);
//     return true;
// }

// template <typename T>
// bool LinkList<T>::index(int idx, T &elem)
// {
//     if (idx < 1 || idx > this->GetLen())
//     {
//         cerr << "subscript wrong!" << endl;
//         return false;
//     }
//     Node<T> *newnode = this->head->next;
//     int counter = 1;
//     while (counter < idx)
//     {
//         counter++;
//         newnode = newnode->next;
//     }
//     elem = newnode->data;
//     return true;
// }

// template <typename T>
// int LinkList<T>::index(bool(*compare(T, T)), T elem)
// {
//     Node<T> *newnode = this->head;
//     int counter = 0;
//     while (newnode->next != nullptr)
//     {
//         newnode = newnode->next;
//         counter++;
//         if (compare(newnode->data, elem))
//         {
//             return counter;
//         }
//     }
//     return -1;
// }
// template <typename T>
// void LinkList<T>::traverse(void (*print)(T &elem))
// {
//     Node<T> *tmp = this->head->next;
//     while (tmp)
//     {
//         print(tmp->data);
//         tmp = tmp->next;
//     }
//     cout << endl;
// }

// /* 用于定义非成员函数 */
// template <typename T>
// void show(LinkList<T> &L)
// {
//     cout << "length : " << L.GetLen() << endl;
// }

// template <typename T>
// void print(T &elem)
// {
//     cout << elem << " ";
// }