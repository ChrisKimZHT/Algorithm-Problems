#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    bool light[2000100] = {false};
    int n;
    cin >> n;
    while (n--)
    {
        double a;
        int t;
        cin >> a >> t;
        for (int i = 1; i <= t;i++)
        {
            light[(int)(a * i)] = (light[(int)(a * i)]) ? false : true;
        }
    }
    for (int i = 1; i <= 2000000;i++)
    {
        if(light[i])
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}