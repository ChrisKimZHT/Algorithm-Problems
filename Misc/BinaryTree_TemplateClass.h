//
// Created by ChrisKim on 2022/11/4.
//

#ifndef EXPERIMENT_DSA_03_BINARY_TREE_H
#define EXPERIMENT_DSA_03_BINARY_TREE_H

#include <string>
#include <algorithm>
#include "list_stack.h"

template<typename T>
class BinaryTree
{
private:
    T value{};
    BinaryTree *left_child{};
    BinaryTree *right_child{};

public:
    BinaryTree(const std::string &str)
    {
        std::string root_str, left_str, right_str;
        int i = 0;
        for (; i < str.size(); i++) // 分离根节点表示
        {
            if (str[i] == '(')
            {
                i++;
                break;
            }
            root_str += str[i];
        }
        int brace_cnt = 0;
        for (; i < str.size(); i++) // 分离左子节点表示
        {
            if (str[i] == '(')
                brace_cnt++;
            else if (str[i] == ')')
                brace_cnt--;
            if (!brace_cnt && str[i] == ',')
            {
                i++;
                break;
            }
            left_str += str[i];
        }
        right_str = str.substr(i, str.size() - i - 1); // 分离右子节点表示
        value = T(root_str);
        if (!left_str.empty())
            left_child = new BinaryTree(left_str);
        if (!right_str.empty())
            right_child = new BinaryTree(right_str);
    }
    ~BinaryTree()
    {
        delete left_child;
        delete right_child;
    }
    // 前序遍历递归法
    std::string preorderTraversal()
    {
        std::string ans;
        ans += std::string(value);
        if (left_child)
            ans += left_child->preorderTraversal();
        if (right_child)
            ans += right_child->preorderTraversal();
        return ans;
    }
    // 中序遍历递归法
    std::string inorderTraversal()
    {
        std::string ans;
        if (left_child)
            ans += left_child->inorderTraversal();
        ans += std::string(value);
        if (right_child)
            ans += right_child->inorderTraversal();
        return ans;
    }
    // 后序遍历递归法
    std::string postorderTraversal()
    {
        std::string ans;
        if (left_child)
            ans += left_child->postorderTraversal();
        if (right_child)
            ans += right_child->postorderTraversal();
        ans += std::string(value);
        return ans;
    }
    // 前序遍历非递归法
    std::string preorderTraversalNotRecursion()
    {
        std::string ans;
        ListStack<BinaryTree<T> *> stk;
        BinaryTree<T> *node = this;
        while (node || stk.size())
        {
            if (node)
            {
                ans += std::string(node->value);
                stk.push(node);
                node = node->left_child;
            }
            else
            {
                node = stk.top();
                stk.pop();
                node = node->right_child;
            }
        }
        return ans;
    }
    // 中序遍历非递归法
    std::string inorderTraversalNotRecursion()
    {
        std::string ans;
        ListStack<BinaryTree<T> *> stk;
        BinaryTree<T> *node = this;
        while (node || stk.size())
        {
            if (node)
            {
                stk.push(node);
                node = node->left_child;
            }
            else
            {
                node = stk.top();
                ans += std::string(node->value);
                stk.pop();
                node = node->right_child;
            }
        }
        return ans;
    }
    // 后序遍历非递归法
    std::string postorderTraversalNotRecursion()
    {
        std::string ans;
        ListStack<BinaryTree<T> *> stk;
        BinaryTree<T> *node = this;
        while (node || stk.size())
        {
            if (node)
            {
                ans += std::string(node->value);
                stk.push(node);
                node = node->right_child;
            }
            else
            {
                node = stk.top();
                stk.pop();
                node = node->left_child;
            }
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

template<>
class BinaryTree<std::string>
{
private:
    std::string value{};
    int depth{}; // 该题家族树特别的深度，非二叉树深度！
    BinaryTree *left_child{};
    BinaryTree *right_child{};

public:
    BinaryTree(const std::string &str, int dep = 0)
    {
        depth = dep;
        std::string root_str, left_str, right_str;
        int i = 0;
        for (; i < str.size(); i++) // 分离根节点表示
        {
            if (str[i] == '(')
            {
                i++;
                break;
            }
            root_str += str[i];
        }
        int brace_cnt = 0;
        for (; i < str.size(); i++) // 分离左子节点表示
        {
            if (str[i] == '(')
                brace_cnt++;
            else if (str[i] == ')')
                brace_cnt--;
            if (!brace_cnt && str[i] == ',')
            {
                i++;
                break;
            }
            left_str += str[i];
        }
        right_str = str.substr(i, str.size() - i - 1); // 分离右子节点表示
        value = std::string(root_str);
        if (!left_str.empty())
            left_child = new BinaryTree(left_str, dep + 1);
        if (!right_str.empty())
            right_child = new BinaryTree(right_str, dep);
    }
    ~BinaryTree()
    {
        delete left_child;
        delete right_child;
    }
    // 前序遍历递归法
    std::string preorderTraversal()
    {
        std::string ans;
        ans += std::string(value);
        if (left_child)
            ans += left_child->preorderTraversal();
        if (right_child)
            ans += right_child->preorderTraversal();
        return ans;
    }
    // 中序遍历递归法
    std::string inorderTraversal()
    {
        std::string ans;
        if (left_child)
            ans += left_child->inorderTraversal();
        ans += std::string(value);
        if (right_child)
            ans += right_child->inorderTraversal();
        return ans;
    }
    // 后序遍历递归法
    std::string postorderTraversal()
    {
        std::string ans;
        if (left_child)
            ans += left_child->postorderTraversal();
        if (right_child)
            ans += right_child->postorderTraversal();
        ans += std::string(value);
        return ans;
    }
    // 前序遍历非递归法
    std::string preorderTraversalNotRecursion()
    {
        std::string ans;
        ListStack<BinaryTree<std::string> *> stk;
        BinaryTree<std::string> *node = this;
        while (node || stk.size())
        {
            if (node)
            {
                ans += std::string(node->value);
                stk.push(node);
                node = node->left_child;
            }
            else
            {
                node = stk.top();
                stk.pop();
                node = node->right_child;
            }
        }
        return ans;
    }
    // 中序遍历非递归法
    std::string inorderTraversalNotRecursion()
    {
        std::string ans;
        ListStack<BinaryTree<std::string> *> stk;
        BinaryTree<std::string> *node = this;
        while (node || stk.size())
        {
            if (node)
            {
                stk.push(node);
                node = node->left_child;
            }
            else
            {
                node = stk.top();
                ans += std::string(node->value);
                stk.pop();
                node = node->right_child;
            }
        }
        return ans;
    }
    // 后序遍历非递归法
    std::string postorderTraversalNotRecursion()
    {
        std::string ans;
        ListStack<BinaryTree<std::string> *> stk;
        BinaryTree<std::string> *node = this;
        while (node || stk.size())
        {
            if (node)
            {
                ans += std::string(node->value);
                stk.push(node);
                node = node->right_child;
            }
            else
            {
                node = stk.top();
                stk.pop();
                node = node->left_child;
            }
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
    // 取得某个节点的辈分
    int getDepth(std::string node)
    {
        if (node == value)
            return depth;
        if (left_child)
        {
            int ans = left_child->getDepth(node);
            if (ans != -1)
                return ans;
        }
        if (right_child)
        {
            int ans = right_child->getDepth(node);
            if (ans != -1)
                return ans;
        }
        return -1;
    }
    // 输出所有长辈
    std::string getAncestor(std::string node)
    {
        std::string ans;
        std::string str = postorderTraversalNotRecursion();
        int node_depth = getDepth(node);
        for (char &i: str)
        {
            std::string tmp;
            tmp += i;
            if (node_depth > getDepth(tmp))
                ans += i;
        }
        return ans;
    }
};

#endif //EXPERIMENT_DSA_03_BINARY_TREE_H

