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
    int arr[100010];
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quicksort(arr, 0, n - 1);
    cout << arr[k - 1] << endl;
    return 0;
}