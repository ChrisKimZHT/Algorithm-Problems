#include <bits/stdc++.h>

using namespace std;

struct DATA
{
    bool type;
    int length, width;
    // DATA(bool a, int b, int c) : type(a), length(b), width(c){};
};

bool cmp(DATA a, DATA b)
{
    if (a.length != b.length)
        return a.length > b.length;
    else if (a.type != b.type)
        return a.type > b.type;
    else
        return false;
}

int main(void)
{
    int N, M;
    cin >> N >> M;
    vector<DATA> lst(N + M);
    for (int i = 0; i < N; i++)
    {
        lst[i].type = 0;
        cin >> lst[i].width;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> lst[i].length;
    }
    for (int i = N; i < N + M; i++)
    {
        lst[i].type = 1;
        cin >> lst[i].width;
    }
    for (int i = N; i < N + M; i++)
    {
        cin >> lst[i].length;
    }
    sort(lst.begin(), lst.end(), cmp);
    multiset<int> st;
    bool flag = true;
    for (auto it : lst)
    {
        if (it.type)
        {
            st.insert(it.width);
        }
        else
        {
            if (st.lower_bound(it.width) == st.end())
            {
                flag = false;
                break;
            }
            else
            {
                st.erase(st.lower_bound(it.width));
            }
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}