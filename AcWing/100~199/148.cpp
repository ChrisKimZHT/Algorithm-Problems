#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;
int n;
priority_queue<int, vector<int>, greater<int>> pque;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        pque.push(t);
    }
    int ans = 0;
    while (pque.size() > 1)
    {
        int a = pque.top();
        pque.pop();
        int b = pque.top();
        pque.pop();
        int c = a + b;
        ans += c;
        pque.push(c);
    }
    cout << ans << endl;
    return 0;
}