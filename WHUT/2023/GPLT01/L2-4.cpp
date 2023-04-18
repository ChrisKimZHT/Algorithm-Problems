#include <bits/stdc++.h>

using namespace std;

vector<bool> sex;

int read()
{
    int input = 0, flag = 0;
    char a = getchar();
    while ((a < '0' || a > '9') && a != '-')
        a = getchar();
    if (a == '-')
    {
        flag = 1;
        a = getchar();
    }
    while (a >= '0' && a <= '9')
    {
        input = input * 10 + a - '0';
        a = getchar();
    }
    sex[input] = flag;
    return input;
}

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> photo(M + 10);
    sex.resize(N + 10);
    for (int i = 0; i < M; i++)
    {
        int K;
        cin >> K;
        photo[i].resize(K);
        for (int j = 0; j < K; j++)
            photo[i][j] = read();
    }
    int A = read(), B = read();
    vector<double> ia(N + 10, 0.0), ib(N + 10, 0.0);
    for (int i = 0; i < M; i++)
    {
        bool havea = find(photo[i].begin(), photo[i].end(), A) != photo[i].end();
        bool haveb = find(photo[i].begin(), photo[i].end(), B) != photo[i].end();
        if (havea)
        {
            for (int j = 0; j < photo[i].size(); j++)
                if (sex[photo[i][j]] != sex[A])
                    ia[photo[i][j]] += 1.0 / photo[i].size();
        }
        if (haveb)
        {
            for (int j = 0; j < photo[i].size(); j++)
                if (sex[photo[i][j]] != sex[B])
                    ib[photo[i][j]] += 1.0 / photo[i].size();
        }
    }
    double ma = *max_element(ia.begin(), ia.end());
    double mb = *max_element(ib.begin(), ib.end());
    if (ia[B] == ma && ib[A] == mb)
    {
        cout << (sex[A] ? "-" : "") << A << ' ' << (sex[B] ? "-" : "") << B << endl;
        return;
    }
    for (int i = 0; i < N; i++)
        if (ma == ia[i])
            cout << (sex[A] ? "-" : "") << A << ' ' << (sex[i] ? "-" : "") << i << endl;
    for (int i = 0; i < N; i++)
        if (mb == ib[i])
            cout << (sex[B] ? "-" : "") << B << ' ' << (sex[i] ? "-" : "") << i << endl;
}

signed main()
{
    solve();
    return 0;
}