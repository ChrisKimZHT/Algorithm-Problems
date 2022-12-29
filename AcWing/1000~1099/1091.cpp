#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 1010;
int a, b, n, ans = INT32_MAX;
int mat[MAXN][MAXN], min_mat[MAXN][MAXN], max_mat[MAXN][MAXN];
int min_arr[MAXN], max_arr[MAXN], tmp[MAXN];

void monotonic_inc_queue(int src[], int res[], int len)
{
    deque<int> q;
    for (int i = 1; i <= len; i++)
    {
        while (q.size() && src[q.back()] > src[i])
            q.pop_back();
        q.push_back(i);
        if (q.size() && q.front() <= i - n)
            q.pop_front();
        res[i] = src[q.front()];
    }
}

void monotonic_dec_queue(int src[], int res[], int len)
{
    deque<int> q;
    for (int i = 1; i <= len; i++)
    {
        while (q.size() && src[q.back()] < src[i])
            q.pop_back();
        q.push_back(i);
        if (q.size() && q.front() <= i - n)
            q.pop_front();
        res[i] = src[q.front()];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> n;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= a; i++)
    {
        monotonic_inc_queue(mat[i], min_mat[i], b);
        monotonic_dec_queue(mat[i], max_mat[i], b);
    }
    for (int j = n; j <= b; j++)
    {
        for (int i = 1; i <= a; i++)
            tmp[i] = min_mat[i][j];
        monotonic_inc_queue(tmp, min_arr, a);
        for (int i = 1; i <= a; i++)
            tmp[i] = max_mat[i][j];
        monotonic_dec_queue(tmp, max_arr, a);
        for (int i = n; i <= a; i++)
            ans = min(ans, max_arr[i] - min_arr[i]);
    }
    cout << ans << endl;
    return 0;
}