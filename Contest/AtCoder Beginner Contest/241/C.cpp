#include <bits/stdc++.h>

using namespace std;

int N;
bool black[1010][1010];

bool check(pair<int, int> x)
{
    int cnt = 0;
    if (x.second + 5 >= 0 && x.second + 5 < N)
    {
        for (int i = 1; i <= 5; i++)
        {
            if (!black[x.first][x.second + i])
            {
                cnt++;
            }
        }
        if (cnt <= 2)
            return true;
    }
    cnt = 0;
    if (x.second - 5 >= 0 && x.second - 5 < N)
    {
        for (int i = 1; i <= 5; i++)
        {
            if (!black[x.first][x.second - i])
            {
                cnt++;
            }
        }
        if (cnt <= 2)
            return true;
    }
    cnt = 0;
    if (x.first + 5 >= 0 && x.first + 5 < N)
    {
        for (int i = 1; i <= 5; i++)
        {
            if (!black[x.first + i][x.second])
            {
                cnt++;
            }
        }
        if (cnt <= 2)
            return true;
    }
    cnt = 0;
    if (x.first - 5 >= 0 && x.first - 5 < N)
    {
        for (int i = 1; i <= 5; i++)
        {
            if (!black[x.first - i][x.second])
            {
                cnt++;
            }
        }
        if (cnt <= 2)
            return true;
    }
    cnt = 0;
    if (x.first + 5 >= 0 && x.first + 5 < N && x.second + 5 >= 0 && x.second + 5 < N)
    {
        for (int i = 1; i <= 5; i++)
        {
            if (!black[x.first + i][x.second + i])
            {
                cnt++;
            }
        }
        if (cnt <= 2)
            return true;
    }
    cnt = 0;
    if (x.first - 5 >= 0 && x.first - 5 < N && x.second - 5 >= 0 && x.second - 5 < N)
    {
        for (int i = 1; i <= 5; i++)
        {
            if (!black[x.first - i][x.second - i])
            {
                cnt++;
            }
        }
        if (cnt <= 2)
            return true;
    }
    cnt = 0;
    if (x.first + 5 >= 0 && x.first + 5 < N && x.second - 5 >= 0 && x.second - 5 < N)
    {
        for (int i = 1; i <= 5; i++)
        {
            if (!black[x.first + i][x.second - i])
            {
                cnt++;
            }
        }
        if (cnt <= 2)
            return true;
    }
    cnt = 0;
    if (x.first - 5 >= 0 && x.first - 5 < N && x.second + 5 >= 0 && x.second + 5 < N)
    {
        for (int i = 1; i <= 5; i++)
        {
            if (!black[x.first - i][x.second + i])
            {
                cnt++;
            }
        }
        if (cnt <= 2)
            return true;
    }
    return false;
}

int main(void)
{
    cin >> N;
    queue<pair<int, int>> blk;
    for (int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < N; j++)
        {
            if (tmp[j] == '#')
            {
                black[i][j] = true;
                blk.push(make_pair(i, j));
            }
        }
    }
    bool flag = false;
    while (!blk.empty())
    {
        if (check(blk.front()))
        {
            flag = true;
            break;
        }
        blk.pop();
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}