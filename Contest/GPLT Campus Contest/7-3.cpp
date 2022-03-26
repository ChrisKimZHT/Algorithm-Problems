#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    int mx, my;
    cin >> mx >> my;
    int posx[1000], posy[1000];
    for (int i = 0; i < n; i++)
        cin >> posx[i] >> posy[i];
    int distpow2[1000];
    int cnt = 0, mind = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        distpow2[i] = (posx[i] - mx) * (posx[i] - mx) + (posy[i] - my) * (posy[i] - my);
        if (distpow2[i] <= d * d)
        {
            cnt++;
            mind = min(mind, distpow2[i]);
        }
    }
    if (cnt)
    {
        cout << cnt << ' ' << mind << endl;
    }
    else
    {
        cout << cnt << " -1" << endl;
    }
}