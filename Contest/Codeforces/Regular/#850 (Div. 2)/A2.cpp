#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    n--;
    int alice_w = 1, alice_b = 0, bob_w = 0, bob_b = 0;
    int now = 1, cnt = 0, color = 1;
    for (int i = 2;; i++)
    {
        if (n < i)
        {
            if (now == 0)
            {
                if (n % 2)
                {
                    alice_w += n / 2 + (1 - color);
                    alice_b += n / 2 + color;
                }
                else
                {
                    alice_w += n / 2;
                    alice_b += n / 2;
                }
            }
            else
            {
                if (n % 2)
                {
                    bob_w += n / 2 + (1 - color);
                    bob_b += n / 2 + color;
                }
                else
                {
                    bob_w += n / 2;
                    bob_b += n / 2;
                }
            }
            break;
        }
        if (now == 0)
        {
            if (i % 2)
            {
                alice_w += i / 2 + (1 - color);
                alice_b += i / 2 + color;
            }
            else
            {
                alice_w += i / 2;
                alice_b += i / 2;
            }
        }
        else
        {
            if (i % 2)
            {
                bob_w += i / 2 + (1 - color);
                bob_b += i / 2 + color;
            }
            else
            {
                bob_w += i / 2;
                bob_b += i / 2;
            }
        }
        n -= i;
        cnt++;
        if (i % 2)
            color = 1 - color;
        if (cnt == 2)
        {
            now = 1 - now;
            cnt = 0;
        }
    }
    cout << alice_w << ' ' << alice_b << ' ' << bob_w << ' ' << bob_b << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}