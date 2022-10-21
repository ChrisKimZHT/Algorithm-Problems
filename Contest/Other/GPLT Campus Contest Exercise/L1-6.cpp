#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int num;
        cin >> num;
        int awa[10]{};
        bool flag = true;
        for (int i = 2; i <= 9; i++)
        {
            int multi = num * i;
            while (multi)
            {
                awa[i - 2] += multi % 10;
                multi /= 10;
            }
            if (i > 2 && awa[i - 2] != awa[i - 3])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << awa[0] << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}