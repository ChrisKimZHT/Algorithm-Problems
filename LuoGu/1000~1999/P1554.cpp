#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int M, N, digit[10] = {0};
    cin >> M >> N;
    for (int i = M; i <= N;i++)
    {
        int num = i;
        while(num)
        {
            digit[num % 10]++;
            num /= 10;
        }
    }
    for (int i = 0; i < 10;i++)
    {
        cout << digit[i] << " ";
    }
    cout << endl;
    return 0;
}