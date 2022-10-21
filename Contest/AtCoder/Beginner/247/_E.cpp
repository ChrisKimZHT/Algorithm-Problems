#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
int N, X, Y;
int A[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> X >> Y;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int i = 0;
    long long ans = 0;
    while (i < N)
    {
        vector<int> subseq;
        while (i < N && A[i] >= Y && A[i] <= X)
        {
            subseq.push_back(A[i]);
            i++;
        }
        if (!subseq.empty())
        {
            int l = 0, r = 0;
            int cnt_X = 0, cnt_Y = 0;
            if (subseq[0] == X)
                cnt_X++;
            if (subseq[0] == Y)
                cnt_Y++;
            while (l < subseq.size() && r < subseq.size())
            {
                if (!cnt_X || !cnt_Y)
                {
                    r++;
                    if (subseq[r] == X)
                        cnt_X++;
                    if (subseq[r] == Y)
                        cnt_Y++;
                }
                else
                {
                    ans += subseq.size() - r;
                    if (subseq[l] == X)
                        cnt_X--;
                    if (subseq[l] == Y)
                        cnt_Y--;
                    l++;
                }
            }
        }
        else
        {
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}