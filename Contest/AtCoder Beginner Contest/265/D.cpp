#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
int N;
long long P, Q, R;
long long ps[MAXN];

bool find(int start)
{
    if (start >= N)
        return false;
    int pl = start, pr = lower_bound(ps, ps + N + 1, P + ps[pl - 1]) - ps;
    // cout << "P: " << pl << ' ' << pr << endl;
    if (pl > N || pr > N || ps[pr] - ps[pl - 1] != P)
        return find(pl + 1);
    int ql = pr + 1, qr = lower_bound(ps, ps + N + 1, Q + ps[ql - 1]) - ps;
    // cout << "Q: " << ql << ' ' << qr << endl;
    if (ql > N || qr > N || ps[qr] - ps[ql - 1] != Q)
        return find(pl + 1);
    int rl = qr + 1, rr = lower_bound(ps, ps + N + 1, R + ps[rl - 1]) - ps;
    // cout << "R: " << rl << ' ' << rr << endl;
    if (rl > N || rr > N || ps[rr] - ps[rl - 1] != R)
        return find(pl + 1);
    return true;
}

int main()
{
    cin >> N >> P >> Q >> R;
    for (int i = 1; i <= N; i++)
    {
        cin >> ps[i];
        ps[i] += ps[i - 1];
    }
    bool flag = find(1);
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}