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
    string S;
    cin >> S;
    bool flag = false;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == '"')
            flag = !flag;
        else if (S[i] == ',' && !flag)
            S[i] = '.';
    }
    cout << S << endl;
    return 0;
}