#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int N;
int num[MAXN];
// stack<int> st;
int st[MAXN], idx;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    // for (int i = 0; i < N; i++)
    // {
    //     while (!st.empty() && num[st.top()] >= num[i])
    //         st.pop();
    //     cout << (st.empty() ? -1 : num[st.top()]) << ' ';
    //     st.push(i);
    // }
    for (int i = 0; i < N; i++)
    {
        while (idx && num[st[idx]] >= num[i])
            idx--;
        cout << (!idx ? -1 : num[st[idx]]) << ' ';
        st[++idx] = i;
    }
    cout << endl;
    return 0;
}