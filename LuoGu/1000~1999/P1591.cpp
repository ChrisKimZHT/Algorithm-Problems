#include <bits/stdc++.h>

using namespace std;

int ans[1010][10];

vector<int> b_mul(vector<int> &a, int b)
{
    vector<int> ans;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t = t + a[i] * b;
        ans.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        ans.push_back(t % 10);
        t /= 10;
    }
    return ans;
}

void init()
{
    vector<int> big_num;
    big_num.push_back(1);
    for (int i = 1; i <= 1000; i++)
    {
        big_num = b_mul(big_num, i);
        for (auto n : big_num)
            ans[i][n]++;
    }
}

int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
    {
        int n, a;
        cin >> n >> a;
        cout << ans[n][a] << endl;
    }
    return 0;
}