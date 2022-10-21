#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    long long date;
    cin >> date;
    if (date > INT32_MAX)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    stringstream ans;
    for (int i = 0; i < 14; i++)
    {
        if (i == 2 || i == 5 || i == 8 || i == 11)
            ans << '-';
        else
        {
            ans << date % 10;
            date /= 10;
        }
    }
    string output = ans.str();
    for (int i = output.size() - 1; i >= 0; i--)
        cout << output[i];
    cout << endl;
    return 0;
}