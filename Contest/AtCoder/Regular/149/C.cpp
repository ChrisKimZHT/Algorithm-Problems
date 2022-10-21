#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> mat_arr;
    if (N == 3)
        mat_arr = {5, 9, 1, 3, 7, 8, 6, 2, 4};
    else if (N == 4)
        mat_arr = {9, 11, 13, 15, 1, 3, 5, 7, 8, 6, 4, 2, 10, 12, 14, 16};
    else if (N == 5)
        mat_arr = {5, 7, 11, 13, 17, 19, 23, 25, 21, 1, 3, 9, 15, 24, 8, 6, 12, 18, 2, 4, 10, 14, 16, 20, 22};
    else
    {
        for (int i = 1; i <= N * N; i++)
            if ((i % 2) && (i % 3))
                mat_arr.push_back(i);
        for (int i = 1; i <= N * N; i++)
            if ((i % 2) && !(i % 3))
                mat_arr.push_back(i);
        for (int i = 1; i <= N * N; i++)
            if (!(i % 2) && !(i % 3))
                mat_arr.push_back(i);
        for (int i = 1; i <= N * N; i++)
            if (!(i % 2) && (i % 3))
                mat_arr.push_back(i);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << mat_arr[i * N + j] << ' ';
        cout << endl;
    }
    return 0;
}