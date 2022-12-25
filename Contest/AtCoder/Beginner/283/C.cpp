#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string S;
    cin >> S;
    int dbzero = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '0' && S[i + 1] == '0')
        {
            dbzero++;
            i++;
        }
    }
    cout << S.size() - dbzero << endl;
    return 0;
}