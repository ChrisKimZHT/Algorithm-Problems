#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b, a || b)
    {
        bool flag = false;
        a *= 100;
        for (int i = 0; i < 100; i++)
        {
            if (!((a + i) % b))
            {
                if (flag)
                    cout << ' ';
                printf("%02d", i);
                flag = true;
            }
        }
        cout << endl;
    }
    return 0;
}