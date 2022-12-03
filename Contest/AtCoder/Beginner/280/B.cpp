#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<long long> S(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> S[i];
    for (int i = 1; i <= N; i++)
        cout << S[i] - S[i - 1] << ' ';
    cout << endl;
    return 0;
}