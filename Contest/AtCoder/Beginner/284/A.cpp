#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<string> S(N);
    for (auto &ele : S)
        cin >> ele;
    reverse(S.begin(), S.end());
    for (auto &ele : S)
        cout << ele << endl;
    return 0;
}