#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<int> normalize(vector<int> &v)
{
    bool is_adj = false;
    int last = -3;
    int cnt_odd = 0;
    for (auto ele : v)
        if (ele % 2)
            cnt_odd++;
    if (cnt_odd == v.size())
        return v;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] % 2)
        {
            if (i - last <= 2)
            {
                is_adj = true;
                break;
            }
            last = i;
        }
    }
    if (!is_adj)
    {
        last = -1;
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
    else
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
    if (normalize(A) == normalize(B))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}