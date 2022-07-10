#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr(3);
    cin >> arr[0] >> arr[1] >> arr[2];
    int tmp = arr[1];
    sort(arr.begin(), arr.end());
    if (tmp == arr[1])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}