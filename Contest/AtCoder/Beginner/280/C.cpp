#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string S, T;
    cin >> S >> T;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] != T[i])
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << S.size() + 1 << endl;
    return 0;
}