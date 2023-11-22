#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, num[110], count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for (int k = 0; k < n; k++)
    {
        bool brk = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (i == k)
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (j == k)
                    continue;
                if (num[i] + num[j] == num[k])
                {
                    count++;
                    brk = true;
                }
            }
            if(brk)
                break;
        }
    }
    cout << count << endl;
    return 0;
}