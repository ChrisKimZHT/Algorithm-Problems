#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
#define SIZE 210
#define INT32_MAX 2147483647

using namespace std;

int n, cse = 0;
vector<pair<int, int>> stone;
double dist[SIZE][SIZE];

void floyd_init(void)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = INT32_MAX;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }
}

void floyd(void)
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][k] < INT32_MAX && dist[k][j] < INT32_MAX)
                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
}

int main(void)
{
    while (cin >> n && n)
    {
        stone.clear();
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            stone.push_back(make_pair(x, y));
        }
        floyd_init();
        for (int i = 0; i < stone.size() - 1; i++)
        {
            for (int j = i + 1; j < stone.size(); j++)
            {
                dist[i + 1][j + 1] = dist[j + 1][i + 1] = sqrt(pow(stone[i].first - stone[j].first, 2) + pow(stone[i].second - stone[j].second, 2));
            }
        }
        floyd();
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", ++cse, dist[1][2]);
    }
    return 0;
}