#include <bits/stdc++.h>

using namespace std;

void print(int a, int b)
{
    for (int i = a; i + 1 <= b; i++)
    {
        cout << i + 1 << ' ' << i + 2 << endl;
    }
    for (int i = b - 1; i - 1 >= a; i--)
    {
        cout << i << ' ' << i + 1 << endl;
    }
}

int main(void)
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[1010], b[1010];
        map<int, int> cnta, cntb;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            cnta[a[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            cntb[b[i]]++;
        }
        if (cnta != cntb)
        {
            cout << "NO" << endl;
        }
        else
        {
            int step = 0;
            vector<pair<int, int>> exchange;
            for (int i = 0; i < n; i++)
            {
                if (a[i] != b[i])
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        if (a[j] != b[j] && a[j] == b[i])
                        {
                            exchange.push_back({i, j});
                            step += 2 * (j - i) - 1;
                            swap(a[j], a[i]);
                        }
                    }
                }
            }
            if (step <= n * n)
            {
                cout << "YES" << endl;
                for (auto i : exchange)
                {
                    print(i.first, i.second);
                }
                cout << "0 0" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}