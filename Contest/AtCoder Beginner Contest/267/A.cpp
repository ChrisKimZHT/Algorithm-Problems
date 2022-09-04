#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string, int> mp{
        {"Monday", 5},
        {"Tuesday", 4},
        {"Wednesday", 3},
        {"Thursday", 2},
        {"Friday", 1}};
    string in;
    cin >> in;
    cout << mp[in] << endl;
    return 0;
}