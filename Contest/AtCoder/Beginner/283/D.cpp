#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string S;
    cin >> S;
    stack<int> stk;
    vector<bool> st(26);
    bool flag = true;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '(')
        {
            stk.push(-1); // -1 = (
            continue;
        }
        else if (isalpha(S[i]))
        {
            int c = S[i] - 'a';
            if (!st[c])
            {
                st[c] = true;
                stk.push(c);
            }
            else
            {
                flag = false;
                break;
            }
        }
        else if (S[i] == ')')
        {
            int cnt = 1;
            while (stk.size())
            {
                int top = stk.top();
                if (top == -1)
                {
                    if (!cnt)
                        break;
                    cnt--;
                    stk.pop();
                }
                else if (top == -2)
                {
                    cnt++;
                    stk.pop();
                }
                else
                {
                    st[top] = false;
                    stk.pop();
                }
            }
            stk.push(-2); // -2 = )
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}