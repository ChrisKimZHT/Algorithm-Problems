#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h1, h2, h3, w1, w2, w3;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
    int ans = 0;
    // a b c
    // d e f
    // g h i
    for (int a = 1; a <= 30; a++)
    {
        for (int c = 1; c <= 30; c++)
        {
            for (int g = 1; g <= 30; g++)
            {
                for (int i = 1; i <= 30; i++)
                {
                    int b = h1 - a - c;
                    int h = h3 - g - i;
                    int d = w1 - a - g;
                    int f = w3 - c - i;
                    int e = h2 - d - f;
                    if (b > 0 && h > 0 && d > 0 && f > 0 && e > 0 && b + e + h == w2)
                        ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}