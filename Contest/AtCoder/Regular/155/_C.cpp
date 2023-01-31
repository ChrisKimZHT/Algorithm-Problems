#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

// 计算类型: 0-无相邻 1-有相邻 2-全奇数
int type(vector<int> &v)
{
    int last = -3, cnt_odd = 0, ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] % 2)
        {
            if (i - last <= 2)
                ans = 1;
            last = i;
            cnt_odd++;
        }
    }
    if (cnt_odd == v.size())
        ans = 2;
    return ans;
}

// 计算标准型
vector<int> norm(vector<int> &v, int type)
{
    if (type == 0)
    {
        int last = -1;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] % 2)
            {
                if (i - last >= 4)
                    sort(v.begin() + last + 1, v.begin() + i);
                last = i;
            }
        }
        sort(v.begin() + last + 1, v.end());
        return v;
    }
    else if (type == 1)
    {
        vector<int> odd, even;
        for (auto ele : v)
        {
            if (ele % 2)
                odd.push_back(ele);
            else
                even.push_back(ele);
        }
        sort(odd.begin(), odd.end());
        if (even.size() >= 3)
            sort(even.begin(), even.end());
        odd.insert(odd.end(), even.begin(), even.end());
        return odd;
    }
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    int ia = type(A), ib = type(B); // 计算类型
    if (ia != ib)                   // 类型不同直接判假
        cout << "No" << endl;
    else if (ia == 2) // 若均为全奇数类型，比对原型
        cout << (A == B ? "Yes" : "No") << endl;
    else // 若为无相邻或有相邻类型，比对标准型
        cout << (norm(A, ia) == norm(B, ib) ? "Yes" : "No") << endl;
    return 0;
}