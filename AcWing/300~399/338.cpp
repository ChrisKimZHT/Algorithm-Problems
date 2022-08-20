#include <bits/stdc++.h>

using namespace std;

int p10[10];

int get(vector<int> &num, int l, int r)
{
    int res = 0;
    for (int i = l; i >= r; i--)
        res = res * 10 + num[i];
    return res;
}

int count(int lim, int dig)
{
    if (!lim)
        return 0;
    vector<int> num;
    while (lim)
    {
        num.push_back(lim % 10);
        lim /= 10;
    }
    int res = 0;
    for (int i = num.size() - 1 - !dig; i >= 0; i--)
    {
        if (i < num.size() - 1)
        {
            res += get(num, num.size() - 1, i + 1) * p10[i];
            if (!dig)
                res -= p10[i];
        }
        if (num[i] == dig)
            res += get(num, i - 1, 0) + 1;
        else if (num[i] > dig)
            res += p10[i];
    }
    return res;
}

int main()
{
    p10[0] = 1;
    for (int i = 1; i < 10; i++)
        p10[i] = p10[i - 1] * 10;
    int a, b;
    while (cin >> a >> b, a || b)
    {
        if (b < a)
            swap(a, b);
        for (int i = 0; i <= 9; i++)
            cout << count(b, i) - count(a - 1, i) << ' ';
        cout << endl;
    }
    return 0;
}