#include <bits/stdc++.h>

using namespace std;

vector<int> b_mul(vector<int> &a, int b)
{
    vector<int> ans;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i] * b;
        ans.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        ans.push_back(t % 10);
        t /= 10;
    }
    while (ans.size() && !ans.back())
        ans.pop_back();
    return ans;
}

int main()
{
    int n;
    cin >> n;
    set<int> s;
    for (int i = 2;; i++)
    {
        n -= i;
        s.insert(i);
        if (n < 0)
        {
            s.erase(-n);
            break;
        }
    }
    vector<int> ans{1};
    for (auto n : s)
    {
        cout << n << ' ';
        ans = b_mul(ans, n);
    }
    cout << endl;
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    cout << endl;
    return 0;
}