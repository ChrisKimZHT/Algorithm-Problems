#include <bits/stdc++.h>

using namespace std;

const char dig[16] = {'0', '1', '2', '3',
                      '4', '5', '6', '7',
                      '8', '9', 'A', 'B',
                      'C', 'D', 'E', 'F'};

int main()
{
    int num;
    cin >> num;
    vector<char> ans;
    while (num)
    {
        ans.push_back(dig[num % 16]);
        num /= 16;
    }
    while (ans.size() < 2)
        ans.push_back('0');
    cout << ans[1] << ans[0] << endl;
    return 0;
}