#include <bits/stdc++.h>

using namespace std;

string str_or(string &a, string &b)
{
    if (a.size() >= b.size())
    {
        string ans = a;
        for (int i = 0; i < b.size(); i++)
            if (b[i] == '1')
                ans[a.size() - b.size() + i] = '1';
        return ans;
    }
    return str_or(b, a);
}

string remove_zero(string &s)
{
    string ans = s;
    while (ans[0] == '0' && ans.size() - 1)
        ans.erase(ans.begin());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int one = s.find('1'), zero = s.find('0', one);
    string ans = s;
    if (zero != s.npos)
    {
        for (int i = one; i < zero; i++)
        {
            string sub_s = s.substr(i, n - zero);
            ans = max(ans, str_or(s, sub_s));
        }
    }
    cout << remove_zero(ans) << endl;
    return 0;
}