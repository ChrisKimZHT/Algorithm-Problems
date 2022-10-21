#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long long N;
    cin >> N;
    vector<int> onebit;
    for (int i = 0; i < 60; i++)
        if (N >> i & 1)
            onebit.push_back(i);
    for (int i = 0; i < (1LL << onebit.size()); i++)
    {
        long long num = 0;
        for (int j = 0; j < onebit.size(); j++)
            if (i >> j & 1)
                num += 1LL << onebit[j]; // num += pow(2, onebit[j]);
        cout << num << endl;
    }
    return 0;
}