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
    if (S.size() != 8)
    {
        cout << "No" << endl;
        return 0;
    }
    if (!(isupper(S.front()) && isupper(S.back())))
    {
        cout << "No" << endl;
        return 0;
    }
    if (isdigit(S[1]) && isdigit(S[2]) && isdigit(S[3]) && isdigit(S[4]) && isdigit(S[1]) && isdigit(S[5]) && isdigit(S[6]) && S[1] != '0')
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}