#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, P;
    cin >> n >> P;
    vector<long long> value(n);
    for (int i = 0; i < n; i++)
        cin >> value[i];
    sort(value.begin(), value.end());
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int pos1 = upper_bound(value.begin(), value.end(), max(P - value[i], value[i] - P)) - value.begin();
        int pos2 = lower_bound(value.begin(), value.end(), value[i] + P) - value.begin() - 1;
        if (pos2 > pos1)
            ans += pos2 - pos1;
    }
    cout << ans / 2 << endl;
    return 0;
}