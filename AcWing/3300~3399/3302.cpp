#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> pri = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
stack<char> os;
stack<int> ns;

void calc()
{
    char oper = os.top();
    os.pop();
    int a = ns.top();
    ns.pop();
    int b = ns.top();
    ns.pop();
    switch (oper)
    {
    case '+':
        ns.push(b + a);
        break;
    case '-':
        ns.push(b - a);
        break;
    case '*':
        ns.push(b * a);
        break;
    case '/':
        ns.push(b / a);
        break;
    default:
        break;
    }
}

int main()
{
    string exp;
    cin >> exp;
    for (int i = 0; i < exp.size(); i++)
    {
        if (isdigit(exp[i]))
        {
            int pos = i, num = 0;
            while (isdigit(exp[pos]) && pos < exp.size())
            {
                num = num * 10 + exp[pos] - '0';
                pos++;
            }
            ns.push(num);
            i = pos - 1;
        }
        else if (exp[i] == '(')
        {
            os.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (os.top() != '(')
                calc();
            os.pop();
        }
        else
        {
            while (!os.empty() && pri[exp[i]] <= pri[os.top()])
                calc();
            os.push(exp[i]);
        }
    }
    while (!os.empty())
        calc();
    cout << ns.top() << endl;
    return 0;
}