#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 20;
int N, Q;
int x[MAXN];
int which[MAXN], where[MAXN];

int main()
{
    cin >> N >> Q;
    for (int i = 1; i <= Q; i++)
        cin >> x[i];
    for (int i = 1; i <= N; i++)
    {
        which[i] = i;
        where[i] = i;
    }
    for (int i = 1; i <= Q; i++)
    {
        int pos = where[x[i]];
        if (pos < N)
        {
            swap(where[which[pos]], where[which[pos + 1]]);
            swap(which[pos], which[pos + 1]);
        }
        else
        {
            swap(where[which[pos]], where[which[pos - 1]]);
            swap(which[pos], which[pos - 1]);
        }
    }
    for (int i = 1; i <= N; i++)
        cout << which[i] << ' ';
    cout << endl;
    return 0;
}