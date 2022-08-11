#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int arr[MAXN], tmp[MAXN];
void merge_sort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    int a = l, b = mid + 1, idx = 0;
    while (a <= mid && b <= r)
    {
        if (arr[a] <= arr[b])
            tmp[idx++] = arr[a++];
        else
            tmp[idx++] = arr[b++];
    }
    while (a <= mid)
        tmp[idx++] = arr[a++];
    while (b <= r)
        tmp[idx++] = arr[b++];
    for (int i = 0, j = l; j <= r; i++, j++)
        arr[j] = tmp[i];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}