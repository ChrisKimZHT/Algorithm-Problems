#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int N;
int num[MAXN];
int st[MAXN], idx = 0;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    for (int i = 0; i < N; i++)
    {
        while (idx && st[idx] >= num[i])
            idx--;
        cout << (idx ? st[idx] : -1) << ' ';
        st[++idx] = num[i];
    }
    cout << endl;
    return 0;
}