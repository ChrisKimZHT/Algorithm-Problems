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
    vector<string> A(H);
    for (int i = 0; i < H; i++)
        cin >> A[i];
    vector<int> row(H), col(W);
    int Q;
    cin >> Q;
    int start_row = 0, start_col = 0;
    for (int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        start_row = (start_row <= a) ? (a - start_row) : (H - start_row + a);
        start_col = (start_col <= b) ? (b - start_col) : (W - start_col + b);
    }
    if (Q & 1)
    {
        for (int i = 0; i < H; i++)
            row[(start_row - i + H) % H] = i;
        for (int i = 0; i < W; i++)
            col[(start_col - i + W) % W] = i;
    }
    else
    {
        for (int i = 0; i < H; i++)
            row[(start_row + i) % H] = i;
        for (int i = 0; i < W; i++)
            col[(start_col + i) % W] = i;
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            cout << A[row[i]][col[j]];
        cout << endl;
    }
    return 0;
}