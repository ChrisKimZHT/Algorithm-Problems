#include <iostream>

using namespace std;

int primefactor(int);

int main(void)
{
    int N, num, maxpf = 0, ans;
    cin >> N;
    while (N--)
    {
        int temp;
        cin >> num;
        temp = primefactor(num);
        if (temp > maxpf)
        {
            maxpf = temp;
            ans = num;
        }
    }
    cout << ans << endl;
    return 0;
}

int primefactor(int x)
{
    int i;
    for (i = 2;; i++)
    {
        while (1)
        {
            if (x % i == 0)
            {
                x /= i;
            }
            else
            {
                break;
            }
        }
        if (x == 1)
        {
            return i;
        }
    }
}