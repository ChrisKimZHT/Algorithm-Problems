#include <bits/stdc++.h>

using namespace std;

int main()
{
    int Y;
    cin >> Y;
    int ans = Y + 2 - Y % 4;
    cout << (ans >= Y ? ans : ans + 4) << endl;
    return 0;
}