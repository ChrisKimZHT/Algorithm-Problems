#include <bits/stdc++.h>

using namespace std;

void print(int n)
{
    if (n == 1)
    {
        cout << 1 << ' ';
        return;
    }
    else
    {
        print(n - 1);
        cout << n << ' ';
        print(n - 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    print(N);
    return 0;
}