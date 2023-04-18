#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N;
    cin >> N;
    stack<int> num;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        num.push(t);
    }
    stack<char> op;
    for (int i = 0; i < N - 1; i++)
    {
        string s;
        cin >> s;
        op.push(s.front());
    }
    while (op.size())
    {
        int _op = op.top();
        op.pop();
        int _b = num.top();
        num.pop();
        int _a = num.top();
        num.pop();
        if (_op == '+')
            num.push(_a + _b);
        else if (_op == '-')
            num.push(_a - _b);
        else if (_op == '*')
            num.push(_a * _b);
        else if (_op == '/' && _b != 0)
            num.push(_a / _b);
        else
        {
            cout << "ERROR: " << _a << "/0" << endl;
            return;
        }
    }
    cout << num.top() << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}