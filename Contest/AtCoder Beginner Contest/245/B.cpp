#include <bits/stdc++.h>

using namespace std;

bool num[2020];

int main(void)
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        num[t] = true;
    }
    for (int i = 0; i <= 2000; i++)
    {
        if (!num[i])
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}