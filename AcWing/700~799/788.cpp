#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int tmp[MAXN], arr[MAXN];

long long merge_sort(int arr[], int l, int r)
{
    if (l >= r)
        return 0;
    int mid = (l + r) / 2;
    long long ans = merge_sort(arr, l, mid) + merge_sort(arr, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
            ans += mid - i + 1;
        }
    }
    while (i <= mid)
        tmp[k++] = arr[i++];
    while (j <= r)
        tmp[k++] = arr[j++];
    for (int m = l, n = 0; m <= r; m++, n++)
        arr[m] = tmp[n];
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << merge_sort(arr, 0, n - 1) << endl;
    return 0;
}