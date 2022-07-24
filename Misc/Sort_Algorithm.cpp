#include <bits/stdc++.h>

using namespace std;

void bubble_sort(int arr[], int l, int r)
{
    for (int i = r; i >= l + 1; i--)
    {
        bool swapped = false;
        for (int j = l + 1; j <= i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                swapped = true;
            }
        }
        if (!swapped)
            return;
    }
}

void selection_sort(int arr[], int l, int r)
{
    for (int i = l; i <= r - 1; i++)
    {
        int j_min = i;
        for (int j = i + 1; j <= r; j++)
        {
            if (arr[j] < arr[j_min])
                j_min = j;
        }
        if (j_min != i)
            swap(arr[i], arr[j_min]);
    }
}

void insertion_sort(int arr[], int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        int num = arr[i];
        int j = i - 1;
        while (j >= l && num < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = num;
    }
}

void quicksort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int x = arr[l], i = l - 1, j = r + 1;
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

const int MAXN = 100;
int tmp[MAXN];
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
    int array[10]{1, 5, 2, 5, 8, 0, -1, 2, 4, -3};
    // bubble_sort(array, 0, 9);
    // selection_sort(array, 0, 9);
    // insertion_sort(array, 0, 9);
    // quicksort(array, 0, 9);
    merge_sort(array, 0, 9);
    for (auto num : array)
        cout << num << ' ';
    cout << endl;
    return 0;
}