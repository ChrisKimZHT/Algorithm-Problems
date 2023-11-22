#include <bits/stdc++.h>

using namespace std;

int res[5][5] = {{0, 0, 1, 1, 0},
                 {1, 0, 0, 1, 0},
                 {0, 1, 0, 0, 1},
                 {0, 0, 1, 0, 1},
                 {1, 1, 0, 0, 0}};

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> cirA, cirB;
    for (int i = 0; i < A; i++)
    {
        int t;
        cin >> t;
        cirA.push_back(t);
    }
    for (int i = 0; i < B; i++)
    {
        int t;
        cin >> t;
        cirB.push_back(t);
    }
    int x = 0, y = 0;
    for (int i = 0; i < N; i++)
    {
        int a = cirA[i % A], b = cirB[i % B];
        x += res[a][b];
        y += res[b][a];
    }
    cout << x << ' ' << y << endl;
    return 0;
}