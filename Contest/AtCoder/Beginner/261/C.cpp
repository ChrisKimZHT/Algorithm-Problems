#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    map<string, int> mp;
    while (N--)
    {
        string tmp;
        cin >> tmp;
        int num = mp[tmp]++;
        cout << tmp;
        if (num)
            cout << '(' << num << ')';
        cout << endl;
    }
    return 0;
}