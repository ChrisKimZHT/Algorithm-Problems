#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    // 排序+去重
    set<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        nums.insert(a[i]);
    }
    reverse(a.begin(), a.end());
    int afront = a.front();
    vector<int> numv;
    for (auto t : nums)
        numv.push_back(t);
    // 找比a.back()大的最大缺失项
    int missing_big = -1;
    if (numv.back() != p - 1)
    {
        missing_big = p - 1;
    }
    else
    {
        for (int i = numv.size() - 1; i > 0; i--)
        {
            if (numv[i - 1] != numv[i] - 1)
            {
                missing_big = numv[i] - 1;
                break;
            }
        }
    }
    // 找比a.back()小的最大缺失项
    int missing_small = -1;
    if (numv.front() != 0)
        missing_small = numv.front() - 1;
    int idx_aback = lower_bound(numv.begin(), numv.end(), afront) - numv.begin();
    for (int i = idx_aback; i > 0; i--)
    {
        if (numv[i - 1] != numv[i] - 1)
        {
            missing_small = max(missing_small, numv[i] - 1);
            break;
        }
    }
    // 如果都无缺失
    if (missing_big == -1 && missing_small == -1)
    {
        cout << 0 << endl;
        return;
    }
    // 如果比a.back()小的无缺失
    if (missing_small == -1)
    {
        cout << missing_big - afront << endl;
        return;
    }
    // 比a.back()小的有缺失
    // 首先整个数字会进位
    a.front() = p;
    int tmp = 0;
    for (int i = 0; i < a.size(); i++)
    {
        a[i] += tmp;
        tmp = 0;
        if (a[i] == p)
        {
            a[i] = 0;
            tmp = 1;
        }
    }
    if (tmp)
        a.push_back(1);
    // 排序+去重
    for (auto tmp : a)
        nums.insert(tmp);
    numv.clear();
    for (auto tmp : nums)
        numv.push_back(tmp);
    // 找比a.back()小的最大缺失项
    missing_small = -1;
    idx_aback = lower_bound(numv.begin(), numv.end(), afront) - numv.begin();
    for (int i = idx_aback; i > 0; i--)
    {
        if (numv[i - 1] != numv[i] - 1)
        {
            missing_small = numv[i] - 1;
            break;
        }
    }
    // 如果比a.back()小的无缺失
    if (missing_small == -1)
    {
        cout << p - afront << endl;
        return;
    }
    // 如果比a.back()小的有缺失
    cout << p - afront + missing_small << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}