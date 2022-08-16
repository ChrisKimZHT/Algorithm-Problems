#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
int n, k;
int num[MAXN];
int que[MAXN], head = 0, tail = -1;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < n; i++)
    {
        while (tail >= head && num[que[tail]] > num[i])
            tail--;
        que[++tail] = i;
        if (i >= k - 1)
        {
            if (que[head] <= i - k)
                head++;
            cout << num[que[head]] << ' ';
        }
    }
    cout << endl;
    head = 0, tail = -1;
    for (int i = 0; i < n; i++)
    {
        while (tail >= head && num[que[tail]] < num[i])
            tail--;
        que[++tail] = i;
        if (i >= k - 1)
        {
            if (que[head] <= i - k)
                head++;
            cout << num[que[head]] << ' ';
        }
    }
    cout << endl;
    return 0;
}