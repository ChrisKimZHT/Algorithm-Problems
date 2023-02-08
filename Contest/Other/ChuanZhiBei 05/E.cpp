#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, q, L;
    cin >> n >> m >> q >> L;
    vector<vector<int>> C(n + 10, vector<int>(L + 10));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < L; j++)
            cin >> C[i][j];
    vector<int> d(n + 10);
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    int op, k, posr = 1, posm = 1, monr = m, monm = m;
    bool now_op = true;            // false-r true-m
    vector<int> grade(n + 10, -1); // [1, n]
    vector<int> who(n + 10, -1);   // [1, n] 0-r 1-m
    vector<int> a(n + 10);         // [1, n]
    while (cin >> op >> k)
    {
        if (op == 1)
        {
            now_op = !now_op;
            if (now_op) // m
            {
                while (k--)
                {
                    posm = (posm % n) + 1;
                    if (who[posm] == 1) // m
                    {
                        monm += a[posm];
                    }
                    else if (who[posm] == 0) // r
                    {
                        monm -= a[posm];
                        monr += a[posm];
                    }
                    if (monm < 0)
                    {
                        cout << "Merry" << endl;
                        return 0;
                    }
                }
            }
            else // r
            {
                for (int i = 1; i <= n; i++)
                {
                    if (who[i] == 1) // m
                    {
                        monm += d[i];
                    }
                    else if (who[i] == 0) // r
                    {
                        monr += d[i];
                    }
                }
                while (k--)
                {
                    posr = (posr % n) + 1;
                    if (who[posr] == 1) // m
                    {
                        monr -= a[posr];
                        monm += a[posr];
                    }
                    else if (who[posr] == 0) // r
                    {
                        monr += a[posr];
                    }
                    if (monr < 0)
                    {
                        cout << "Renko" << endl;
                        return 0;
                    }
                }
            }
        }
        else
        {
            if (now_op == false && who[posr] != 1) // r
            {
                int &now_grade = grade[posr];
                while (k--)
                {
                    if (monr >= C[posr][now_grade + 1] && now_grade < L)
                    {
                        who[posr] = 0;
                        monr -= C[posr][now_grade + 1];
                        a[posr] += C[posr][now_grade + 1];
                        now_grade++;
                    }
                    else
                        break;
                }
            }
            else if (now_op == true && who[posm] != 0) // m
            {
                int &now_grade = grade[posm];
                while (k--)
                {
                    if (monm >= C[posm][now_grade + 1] && now_grade < L)
                    {
                        who[posm] = 1;
                        monm -= C[posm][now_grade + 1];
                        a[posm] += C[posm][now_grade + 1];
                        now_grade++;
                    }
                    else
                        break;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (who[i] == 1) // m
        {
            monm += d[i];
        }
        else if (who[i] == 0) // r
        {
            monr += d[i];
        }
    }
    cout << monr << ' ' << monm << endl;
    return 0;
}