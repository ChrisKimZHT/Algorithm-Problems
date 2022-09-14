#include <bits/stdc++.h>

using namespace std;

set<int> s;
void init()
{
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j < i; j++)
            s.insert(i * i - j * j);
}

int main()
{
    init();
    int n;
    cin >> n;
    for (auto i : s)
    {
        n--;
        if (!n)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}