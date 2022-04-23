#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B, C, D, E, F, X;
    cin >> A >> B >> C >> D >> E >> F >> X;
    int dist_T = 0, dist_A = 0;
    for (int i = 0; i < X; i++)
    {
        if (i % (A + C) >= 0 && i % (A + C) < A)
            dist_T += B;
        if (i % (D + F) >= 0 && i % (D + F) < D)
            dist_A += E;
    }
    if (dist_A > dist_T)
        cout << "Aoki" << endl;
    else if (dist_A < dist_T)
        cout << "Takahashi" << endl;
    else
        cout << "Draw" << endl;
    return 0;
}