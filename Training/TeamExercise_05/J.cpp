#include <bits/stdc++.h>

using namespace std;

vector<int> str;

bool judge(int x)
{
    int chr[26];
    bool domin[26];
    memset(chr, 0, sizeof(chr));
    memset(domin, true, sizeof(domin));
    for (int i = 0; i < x; i++)
        chr[str[i]]++;
    for (int j = 0; j < 26; j++)
        domin[j] *= chr[j];
    for (int i = 0; i + x < str.size(); i++)
    {
        chr[str[i]]--;
        chr[str[i + x]]++;
        for (int j = 0; j < 26; j++)
            domin[j] *= chr[j];
    }
    for (int i = 0; i < 26; i++)
    {
        if (domin[i])
            return true;
    }
    return false;
}

int main(void)
{
    string st;
    cin >> st;
    for (auto c : st)
        str.push_back(c - 'a');
    int l = 1, r = str.size();
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (judge(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}