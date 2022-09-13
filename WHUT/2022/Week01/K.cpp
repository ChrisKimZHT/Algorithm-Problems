#include <bits/stdc++.h>

using namespace std;

bool is[1000];
int p3[10];
void init()
{
    for (int i = 1; i <= 9; i++)
        p3[i] = i * i * i;
    for (int i = 100; i <= 999; i++)
    {
        if (p3[i % 10] + p3[i / 10 % 10] + p3[i / 100 % 10] == i)
            is[i] = true;
    }
}

int main()
{
    init();
    int m, n;
    while (cin >> m >> n)
    {
        bool flag = false;
        for (int i = m; i <= n; i++)
        {
            if (is[i])
            {
                if (flag)
                    cout << ' ';
                cout << i;
                flag = true;
            }
        }
        if (flag)
            cout << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}