#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 10;
int A[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, Q;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    cin >> Q;
    while (Q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int k, x;
            cin >> k >> x;
            A[k] = x;
        }
        else
        {
            int k;
            cin >> k;
            cout << A[k] << endl;
        }
    }
    return 0;
}