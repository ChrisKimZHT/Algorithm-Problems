#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;
    map<int, int> noodle;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        noodle[tmp]++;
    }
    bool flag = true;
    for (int i = 0; i < M; i++)
    {
        int tmp;
        cin >> tmp;
        noodle[tmp]--;
        if (noodle[tmp] < 0)
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}