#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 10;
int N, re;
bool st[MAXN];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        if (t > N || st[t])
            re++;
        else
            st[t] = true;
    }
    int L = 1, R = N + 1;
    while (true)
    {
        while (st[L])
            L++;
        while (R && !st[R])
            R--;
        if (re >= 2)
        {
            re -= 2;
            st[L] = true;
        }
        else
        {
            if (R <= L)
                break;
            st[R] = false;
            re++;
        }
    }
    cout << L - 1 << endl;
    return 0;
}