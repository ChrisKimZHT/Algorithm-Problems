#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
int N, Q;

int main()
{
    cin >> N >> Q;
    vector<vector<int>> seq(N);
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        while (t--)
        {
            int num;
            cin >> num;
            seq[i].push_back(num);
        }
    }
    for (int i = 0; i < Q; i++)
    {
        int s, t;
        cin >> s >> t;
        cout << seq[s - 1][t - 1] << endl;
    }
    return 0;
}