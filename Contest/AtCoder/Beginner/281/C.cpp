#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, T;
    cin >> N >> T;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int sum = accumulate(A.begin(), A.end(), 0LL);
    int remain = T % sum;
    for (int i = 0; i < N; i++)
    {
        if (remain > A[i])
        {
            remain -= A[i];
        }
        else
        {
            cout << i + 1 << ' ' << remain << endl;
            break;
        }
    }
    return 0;
}