#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    int sum = 0;
    for (int i = 1; i <= N; i++)
        sum += A[i] * i;
    if (sum > 0)
    {
        int cnt_posi = 0, cnt_nega = 0, pos = 0;
        for (int i = N; i >= 1; i--)
        {
            if (A[i] == 1)
                cnt_posi++;
            else
                cnt_nega++;
            if (cnt_nega > cnt_posi)
            {
                pos = i;
                break;
            }
        }
        if (pos)
        {
            cout << "Yes" << endl;
            for (int i = 1; i < pos; i++)
                cout << i << ' ';
            for (int i = pos; i <= N; i++)
                cout << i + sum << ' ';
            cout << endl;
            return 0;
        }
        cnt_posi = 0, cnt_nega = 0;
        for (int i = 1; i <= N; i++)
        {
            if (A[i] == 1)
                cnt_posi++;
            else
                cnt_nega++;
            if (cnt_posi > cnt_nega)
            {
                pos = i;
                break;
            }
        }
        if (pos)
        {
            cout << "Yes" << endl;
            for (int i = 1; i <= pos; i++)
                cout << i - sum << ' ';
            for (int i = pos + 1; i <= N; i++)
                cout << i << ' ';
            cout << endl;
            return 0;
        }
    }
    else
    {
        int cnt_posi = 0, cnt_nega = 0, pos = 0;
        for (int i = N; i >= 1; i--)
        {
            if (A[i] == 1)
                cnt_posi++;
            else
                cnt_nega++;
            if (cnt_nega < cnt_posi)
            {
                pos = i;
                break;
            }
        }
        if (pos)
        {
            cout << "Yes" << endl;
            for (int i = 1; i < pos; i++)
                cout << i << ' ';
            for (int i = pos; i <= N; i++)
                cout << i - sum << ' ';
            cout << endl;
            return 0;
        }
        cnt_posi = 0, cnt_nega = 0;
        for (int i = 1; i <= N; i++)
        {
            if (A[i] == 1)
                cnt_posi++;
            else
                cnt_nega++;
            if (cnt_posi < cnt_nega)
            {
                pos = i;
                break;
            }
        }
        if (pos)
        {
            cout << "Yes" << endl;
            for (int i = 1; i <= pos; i++)
                cout << i + sum << ' ';
            for (int i = pos + 1; i <= N; i++)
                cout << i << ' ';
            cout << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}