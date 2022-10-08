#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int fi_odd = -1, fi_even = -1;
    for (int i = N - 1; i >= 0; i--)
        if (arr[i] % 2)
        {
            fi_odd = i;
            break;
        }
    for (int i = N - 1; i >= 0; i--)
        if (!(arr[i] % 2))
        {
            fi_even = i;
            break;
        }
    int se_odd = -1, se_even = -1;
    for (int i = fi_odd - 1; i >= 0; i--)
        if (arr[i] % 2)
        {
            se_odd = i;
            break;
        }
    for (int i = fi_even - 1; i >= 0; i--)
        if (!(arr[i] % 2))
        {
            se_even = i;
            break;
        }
    int ans = -1;
    if (fi_odd != -1 && se_odd != -1)
        ans = arr[fi_odd] + arr[se_odd];
    if (fi_even != -1 && se_even != -1)
        ans = max(ans, arr[fi_even] + arr[se_even]);
    cout << ans << endl;
    return 0;
}