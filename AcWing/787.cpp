#include <bits/stdc++.h>

using namespace std;

int tmp[int(1e5 + 10)];
void merge_sort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }
    while (i <= mid)
        tmp[k++] = arr[i++];
    while (j <= r)
        tmp[k++] = arr[j++];
    for (int m = l, n = 0; m <= r; m++, n++)
        arr[m] = tmp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int arr[100010], n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}