#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int MAXN = 310;
    int N, W;
    cin >> N >> W;
    int A[MAXN];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A, A + N);
    set<int> good;
    for (int i = 0; i < N; i++)
    {
        if (A[i] > W)
            break;
        good.insert(A[i]);
    }
    for (int i = 0; i < N; i++)
    {
        if (A[i] + A[i + 1] > W)
            break;
        for (int j = i + 1; j < N; j++)
        {
            if (A[i] + A[j] <= W)
                good.insert(A[i] + A[j]);
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (A[i] + A[i + 1] + A[i + 2] > W)
            break;
        for (int j = i + 1; j < N; j++)
        {
            if (A[i] + A[j] + A[j + 1] > W)
                break;
            for (int k = j + 1; k < N; k++)
            {
                if (A[i] + A[j] + A[k] <= W)
                    good.insert(A[i] + A[j] + A[k]);
            }
        }
    }
    cout << good.size() << endl;
    return 0;
}