#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e6 + 10;
const int MAXM = 2e6;
int M;
long long presum[MAXN];

int main()
{
    for (int i = 1; i < MAXM; i++)
        presum[i] = presum[i - 1] + i;
    cin >> M;
    int l = 1, r = 1;
    while (r < MAXM)
    {
        long long t = presum[r] - presum[l - 1];
        if (t < M)
        {
            r++;
        }
        else if (t > M)
        {
            l++;
        }
        else
        {
            if (l != r)
                cout << l << ' ' << r << endl;
            r++;
        }
    }
    return 0;
}