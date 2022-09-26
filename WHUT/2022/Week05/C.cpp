#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case " << i << ":" << endl;
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        while (q--)
        {
            int A, B;
            cin >> A >> B;
            int l = lower_bound(arr.begin(), arr.end(), A) - arr.begin();
            int r = upper_bound(arr.begin(), arr.end(), B) - arr.begin() - 1;
            cout << r - l + 1 << endl;
        }
    }
    return 0;
}