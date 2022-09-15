#include <bits/stdc++.h>
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

using namespace std;

int main(void)
{
    int s1, s2, s3;
    int count[81] = {0};
    cin >> s1 >> s2 >> s3;
    for (int i = 1;i<=s1;i++)
    {
        for (int j = 1; j <= s2;j++)
        {
            for (int k = 1; k <= s3;k++)
            {
                count[i + j + k]++;
            }
        }
    }
    int maxcnt = -1, ans;
    for (int i = 3; i <= 80; i++)
    {
        if(maxcnt<count[i])
        {
            ans = i;
        }
        maxcnt = max(maxcnt, count[i]);
    }
    cout << ans << endl;
    return 0;
}