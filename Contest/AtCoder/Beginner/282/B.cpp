#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> p;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        int num = 0;
        for (int j = 0; j < M; j++)
        {
            if (s[j] == 'x')
                num = num * 2;
            else
                num = num * 2 + 1;
        }
        p.push_back(num);
    }
    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if ((p[i] | p[j]) == pow(2, M) - 1)
                cnt++;
    cout << cnt << endl;
    return 0;
}