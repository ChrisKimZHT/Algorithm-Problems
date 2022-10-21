#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 20;
int N, Q;
unsigned int hash_a[MAXN], hash_b[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    set<int> st;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        if (st.find(tmp) == st.end())
        {
            st.insert(tmp);
            hash_a[i + 1] = (hash_a[i] + tmp * (tmp + 1326) * (tmp + 9185));
        }
        else
        {
            hash_a[i + 1] = hash_a[i];
        }
    }
    st.clear();
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        if (st.find(tmp) == st.end())
        {
            st.insert(tmp);
            hash_b[i + 1] = (hash_b[i] + tmp * (tmp + 1326) * (tmp + 9185));
        }
        else
        {
            hash_b[i + 1] = hash_b[i];
        }
    }
    cin >> Q;
    while (Q--)
    {
        int a, b;
        cin >> a >> b;
        if (hash_a[a] == hash_b[b])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}