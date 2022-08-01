#include <bits/stdc++.h>

using namespace std;

stack<int> num;
stack<char> oper;
unordered_map<char, int> ump{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void calc()
{
    int a = num.top();
    num.pop();
    int b = num.top();
    num.pop();
    char op = oper.top();
    oper.pop();
    if (op == '+')
        num.push(b + a);
    else if (op == '-')
        num.push(b - a);
    else if (op == '*')
        num.push(b * a);
    else if (op == '/')
        num.push(b / a);
}

int main()
{
    string exp;
    cin >> exp;
    for (int i = 0; i < exp.size(); i++)
    {
        if (isdigit(exp[i]))
        {
            int n = 0, pos = i;
            while (pos < exp.size() && isdigit(exp[pos]))
            {
                n *= 10;
                n += exp[pos] - '0';
                pos++;
            }
            num.push(n);
            i = pos - 1; // 与for循环的++抵消
        }
        else if (exp[i] == '(')
        {
            oper.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (oper.top() != '(')
                calc();
            oper.pop();
        }
        else
        {
            while (oper.size() && ump[oper.top()] >= ump[exp[i]])
                calc();
            oper.push(exp[i]);
        }
    }
    while (oper.size())
        calc();
    cout << num.top() << endl;
    return 0;
}