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
    for (int i = 0; i < H; i++)
        row[i] = i;
    for (int i = 0; i < W; i++)
        col[i] = i;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int r1 = 0, r2 = a - 1; r1 < r2; r1++, r2--)
            swap(row[r1], row[r2]);
        for (int r1 = a, r2 = H - 1; r1 < r2; r1++, r2--)
            swap(row[r1], row[r2]);
        for (int c1 = 0, c2 = b - 1; c1 < c2; c1++, c2--)
            swap(col[c1], col[c2]);
        for (int c1 = b, c2 = W - 1; c1 < c2; c1++, c2--)
            swap(col[c1], col[c2]);
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            cout << A[row[i]][col[j]];
        cout << endl;
    }
    return 0;
}