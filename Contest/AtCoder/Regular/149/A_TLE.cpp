#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> bi_div(vector<int> &a, int b, int &r)
{
    vector<int> ans;
    r = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        r = r * 10 + a[i];
        ans.push_back(r / b);
        r %= b;
    }
    reverse(ans.begin(), ans.end());
    while (ans.size() > 1 && !ans.back())
        ans.pop_back();
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = N; i > 0; i--)
    {
        for (int j = 9; j > 0; j--)
        {
            int r;
            vector<int> num(i, j);
            bi_div(num, M, r);
            if (!r)
            {
                for (int i = 0; i < num.size(); i++)
                    cout << num[i];
                cout << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}