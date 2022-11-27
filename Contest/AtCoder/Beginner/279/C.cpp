#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int H, W;
    cin >> H >> W;
    vector<string> S, T;
    for (int i = 0; i < H; i++)
    {
        string str;
        cin >> str;
        S.push_back(str);
    }
    for (int i = 0; i < H; i++)
    {
        string str;
        cin >> str;
        T.push_back(str);
    }
    map<string, int> mps, mpt;
    for (int i = 0; i < W; i++)
    {
        string str;
        for (int j = 0; j < H; j++)
            str += S[j][i];
        mps[str]++;
    }
    for (int i = 0; i < W; i++)
    {
        string str;
        for (int j = 0; j < H; j++)
            str += T[j][i];
        mpt[str]++;
    }
    for (auto p : mps)
    {
        if(mpt[p.first]!=p.second)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}