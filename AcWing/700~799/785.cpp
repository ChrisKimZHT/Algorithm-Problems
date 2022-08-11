#include <bits/stdc++.h>

using namespace std;

void quicksort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int x = arr[(l + r) / 2], a = l - 1, b = r + 1;
    while (a < b)
    {
        do
        {
            a++;
        } while (arr[a] < x);
        do
        {
            b--;
        } while (arr[b] > x);
        if (a < b)
            swap(arr[a], arr[b]);
    }
    quicksort(arr, l, b);
    quicksort(arr, b + 1, r);
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