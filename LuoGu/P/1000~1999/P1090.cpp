#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pque;
    while (n--)
    {
        int t;
        cin >> t;
        pque.push(t);
    }
    int ans = 0;
    while (pque.size() >= 2)
    {
        int a = pque.top();
        pque.pop();
        int b = pque.top();
        pque.pop();
        ans += a + b;
        pque.push(a + b);
    }
    cout << ans << endl;
    return 0;
}