#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string s[110], t[110];
    for (int i = 0; i < N; i++)
        cin >> s[i] >> t[i];
    bool flag = true;
    for (int i = 0; i < N; i++)
    {
        bool same = false;
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            if (s[i] == s[j] || s[i] == t[j])
                same = true;
        }
        if (same)
        {
            bool same2 = false;
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                    continue;
                if (t[i] == s[j] || t[i] == t[j])
                    same2 = true;
            }
            if (same2)
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}