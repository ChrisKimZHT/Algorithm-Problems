#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int K;
    cin >> K;
    char c = 'A';
    for (int i = 0; i < K; i++)
        cout << char(c + i);
    cout << endl;
    return 0;
}