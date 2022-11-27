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
    cout << (S.find(T) != S.npos ? "Yes" : "No") << endl;
    return 0;
}