#include <bits/stdc++.h>

using namespace std;

int main()
{
    bool num[10]{};
    string S;
    cin >> S;
    for (auto ch : S)
    {
        num[ch - '0'] = true;
    }
    for (int i = 0; i < 10; i++)
    {
        if (!num[i])
            cout << i << endl;
    }
    return 0;
}