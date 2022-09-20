#include <iostream>
#include <string>

using namespace std;

int main()
{
    string n;
    while (cin >> n, n != "0")
    {
        int ans = 0;
        for (int i = 0; i < n.size(); i++)
        {
            ans += n[i] - '0';
            if (ans >= 10)
                ans = ans % 10 + ans / 10;
        }
        cout << ans << endl;
    }
    return 0;
}