#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    while (K--)
    {
        stack<int> color;
        int now = 1;
        bool flag = true;
        for (int i = 0; i < N; i++)
        {
            int t;
            cin >> t;
            while (!color.empty() && color.top() == now)
            {
                color.pop();
                now++;
            }
            if (t == now)
            {
                now++;
                continue;
            }
            else
            {
                color.push(t);
                if (color.size() > M)
                {
                    flag = false;
                }
            }
        }
        while (!color.empty())
        {
            if (color.top() == now)
            {
                now++;
                color.pop();
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}