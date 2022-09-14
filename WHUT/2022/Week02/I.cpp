#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
long long arr[MAXN];
void init()
{
    arr[0] = 7 % 3;
    arr[1] = 11 % 3;
    for (int i = 2; i < MAXN; i++)
        arr[i] = (arr[i - 1] + arr[i - 2]) % 3;
}

int main()
{
    init();
    int n;
    while (cin >> n)
    {
        if (!arr[n])
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}