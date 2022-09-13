#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int SIZE = 510;

int n, k;
int v1, v2;
bool map[SIZE][SIZE];
bool visit[SIZE];
int link[SIZE];

int result;
bool find(int x)
{
    for (int y = 1; y <= v2; y++)
    {
        if (map[x][y] && !visit[y])
        {
            visit[y] = true;
            if (link[y] == 0 || find(link[y]))
            {
                link[y] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> k;
    v1 = v2 = n;
    int x, y;
    memset(map, 0, sizeof(map));
    for (int i = 1; i <= k; i++)
    {
        cin >> x >> y;
        map[x][y] = true;
    }
    for (int x = 1; x <= v1; x++)
    {
        memset(visit, false, sizeof(visit));
        if (find(x))
            result++;
    }
    printf("%d\n", result);
    return 0;
}