#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string S;
    cin >> S;
    map<char, int> m;
    for (int i = 0; i < S.length(); i++)
        m[S[i]]++;
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        for (int i = 0; i < it->second; i++)
        {
            cout << it->first;
        }
    }
    cout << endl;
    return 0;
}