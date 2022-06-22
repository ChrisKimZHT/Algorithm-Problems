#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
int interval[MAXN];
int N, L, R;

int main()
{
    cin >> N;
    while (N--)
    {
        cin >> L >> R;
        interval[L]++;
        interval[R]--;
    }
    int tmp = 0;
    bool flag = true;
    for (int i = 1; i <= 2e5; i++)
    {
        tmp += interval[i];
        if (tmp > 0 && flag == true)
        {
            cout << i << ' ';
            flag = false;
        }
        else if (tmp == 0 && flag == false)
        {
            cout << i << endl;
            flag = true;
        }
    }
    return 0;
}