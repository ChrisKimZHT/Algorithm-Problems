#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a;
}

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), cmp);
    for (auto i : a)
        cout << i;
    cout << endl;
    return 0;
}