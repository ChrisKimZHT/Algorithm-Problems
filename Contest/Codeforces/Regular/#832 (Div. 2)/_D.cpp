#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 2e5 + 10;
int n, q;
int a[MAXN], prexor[MAXN], last_positive[MAXN], last_same_prexor[MAXN];
map<int, int> odd, even;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prexor[i] = prexor[i - 1] ^ a[i];
        last_positive[i] = a[i] ? i : last_positive[i - 1];
        if (i % 2)
        {
            if (even.count(prexor[i]))
                last_same_prexor[i] = even[prexor[i]];
            odd[prexor[i]] = i;
        }
        else
        {
            if (odd.count(prexor[i]))
                last_same_prexor[i] = odd[prexor[i]];
            even[prexor[i]] = i;
        }
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (prexor[l - 1] ^ prexor[r])
            cout << -1 << '\n';
        else if (last_positive[r] < l)
            cout << 0 << '\n';
        else if ((r - l + 1) % 2)
            cout << 1 << '\n';
        else if (!a[l] || !a[r])
            cout << 1 << '\n';
        else if (last_same_prexor[r] >= l)
            cout << 2 << '\n';
        else
            cout << -1 << '\n';
    }
    return 0;
}