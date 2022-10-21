#include <bits/stdc++.h>

using namespace std;

int main()
{
    string pin;
    cin >> pin;
    bool st[7];
    st[0] = (pin[6] == '1');
    st[1] = (pin[3] == '1');
    st[2] = (pin[1] == '1') || (pin[7] == '1');
    st[3] = (pin[0] == '1') || (pin[4] == '1');
    st[4] = (pin[2] == '1') || (pin[8] == '1');
    st[5] = (pin[5] == '1');
    st[6] = (pin[9] == '1');
    bool flag = false;
    for (int i = 0; i < 7; i++)
        if (st[i])
            for (int j = i + 1; j < 7; j++)
                if (!st[j])
                    for (int k = j + 1; k < 7; k++)
                        if (st[k])
                            flag = true;
    if (pin[0] == '1')
        flag = false;
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}