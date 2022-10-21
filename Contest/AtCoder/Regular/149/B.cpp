#include <bits/stdc++.h>

using namespace std;

int lis(vector<int> &arr)
{
    vector<int> t;
    t.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > t.back())
            t.push_back(arr[i]);
        else
            t[lower_bound(t.begin(), t.end(), arr[i]) - t.begin()] = arr[i];
    }
    return t.size();
}

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i].first;
    for (int i = 0; i < N; i++)
        cin >> arr[i].second;
    sort(arr.begin(), arr.end());
    vector<int> num;
    for (int i = 0; i < N; i++)
        num.push_back(arr[i].second);
    cout << N + lis(num) << endl;
    return 0;
}