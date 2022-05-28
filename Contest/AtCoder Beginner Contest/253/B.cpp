#include <bits/stdc++.h>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<pair<int, int>> piece;
    for (int i = 0; i < H; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < W; j++)
        {
            if (line[j] == 'o')
                piece.push_back({i, j});
        }
    }
    cout << abs(piece[0].first - piece[1].first) + abs(piece[0].second - piece[1].second) << endl;
    return 0;
}