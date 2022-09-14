#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int cnt = 0;
        for (auto c : s)
            if (isdigit(c))
                cnt++;
        cout << cnt << endl;
    }
    return 0;
}