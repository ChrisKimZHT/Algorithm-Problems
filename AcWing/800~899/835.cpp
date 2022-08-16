#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
int trie[MAXN][26], cnt[MAXN], idx;

void insert(string &str)
{
    int t = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int c = str[i] - 'a';
        if (!trie[t][c])
            trie[t][c] = ++idx;
        t = trie[t][c];
    }
    cnt[t]++;
}

int query(string &str)
{
    int t = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int c = str[i] - 'a';
        if (!trie[t][c])
            return 0;
        t = trie[t][c];
    }
    return cnt[t];
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        char op;
        string str;
        cin >> op >> str;
        if (op == 'I')
            insert(str);
        else
            cout << query(str) << endl;
    }
    return 0;
}