#include <bits/stdc++.h>

using namespace std;

const int SIZE = 2e5 + 10;

int A[SIZE], B[SIZE];

int fa[SIZE * 2];
inline void init(int n)
{
    for (int i = 0; i < n; i++)
        fa[i] = i;
}

int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x])); // 注意此处的括号，?的优先级比=高
}

inline void merge(int i, int j)
{
    fa[find(i)] = find(j);
}

int main(void)
{
    int N, K;
    cin >> N >> K;
    init(N * 2);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i < N - 1; i++)
    {
        if (abs(A[i] - A[i + 1]) <= K)
            merge(i, i + 1);
        if (abs(A[i] - B[i + 1]) <= K)
            merge(i, i + 1 + N);
        if (abs(B[i] - A[i + 1]) <= K)
            merge(i + N, i + 1);
        if (abs(B[i] - B[i + 1]) <= K)
            merge(i + N, i + 1 + N);
    }
    if (find(0) == find(N - 1) || find(0) == find(2 * N - 1) || find(N) == find(N - 1) || find(N) == find(2 * N - 1))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}