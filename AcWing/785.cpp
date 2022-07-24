#include <bits/stdc++.h>

using namespace std;

void quicksort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int x = arr[(l + r) / 2], i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            i++;
        while (arr[i] < x);
        do
            j--;
        while (arr[j] > x);
        if (i < j)
            swap(arr[i], arr[j]);
    }
    quicksort(arr, l, j);
    quicksort(arr, j + 1, r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int arr[100010], n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}