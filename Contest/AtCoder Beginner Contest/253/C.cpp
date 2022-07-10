#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<int, int> S;
    int Q;
    cin >> Q;
    while (Q--)
    {
        int oper;
        cin >> oper;
        if (oper == 1)
        {
            int x;
            cin >> x;
            S[x]++;
        }
        else if (oper == 2)
        {
            int x, c;
            cin >> x >> c;
            if (S[x] > c)
                S[x] -= c;
            else
            {
                S.erase(x);
            }
        }
        else
        {
            cout << S.rbegin()->first - S.begin()->first << endl;
        }
    }
    return 0;
}