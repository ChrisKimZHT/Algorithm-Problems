#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    multiset<int> l, r;
    int sum = 0;

    for (int i = 0; i < M; i++)
        l.insert(A[i]);
    while (l.size() > K)
    {
        int mx = *l.rbegin();
        r.insert(mx);
        l.extract(mx);
    }
    for (auto &elem : l)
        sum += elem;

    cout << sum << ' ';
    for (int i = 1; i + M - 1 < N; i++)
    {
        int out = A[i - 1], in = A[i + M - 1];
        int lmax = *l.rbegin(), rmin = *r.begin();
        if (r.empty())
        {
            l.extract(out);
            l.insert(in);
            sum += in - out;
        }
        else if (out > lmax && in > lmax)
        {
            r.extract(out);
            r.insert(in);
        }
        else if (out < rmin && in < rmin)
        {
            l.extract(out);
            l.insert(in);
            sum += in - out;
        }
        else if (out < rmin && in > lmax)
        {
            r.insert(in);
            int new_rmin = *r.begin();
            r.extract(new_rmin);
            l.insert(new_rmin);
            l.extract(out);
            sum += new_rmin - out;
        }
        else // if (out > lmax && in < rmin)
        {
            l.insert(in);
            int new_lmax = *l.rbegin();
            l.extract(new_lmax);
            r.insert(new_lmax);
            r.extract(out);
            sum += in - new_lmax;
        }
        cout << sum << ' ';
    }
    cout << endl;
    return 0;
}