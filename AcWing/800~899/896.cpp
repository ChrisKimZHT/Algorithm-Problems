#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int N, num[MAXN];
vector<int> vec;

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> num[i];
    vec.push_back(num[1]);
    for (int i = 2; i <= N; i++)
    {
        if (num[i] > vec.back())
            vec.push_back(num[i]);
        else
            vec[lower_bound(vec.begin(), vec.end(), num[i]) - vec.begin()] = num[i];
    }
    cout << vec.size() << endl;
    return 0;
}