#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 110;
int height[SIZE];
int r2l[SIZE], l2r[SIZE];
int n;

int main(void)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> height[i];
        r2l[i] = l2r[i] = 1;
    }
    for (int i = n - 1; i >= 1; i--)
        for (int j = i + 1; j <= n; j++)
            if (height[i] > height[j] && r2l[i] <= r2l[j] + 1)
                r2l[i] = r2l[j] + 1;
    for (int i = 1; i <= n - 1; i++)
        for (int j = i + 1; j <= n; j++)
            if (height[i] < height[j] && l2r[j] <= l2r[i] + 1)
                l2r[j] = l2r[i] + 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, r2l[i] + l2r[i] - 1);
    cout << n - ans << endl;
    return 0;
}