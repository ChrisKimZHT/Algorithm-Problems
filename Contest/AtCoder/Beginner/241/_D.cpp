#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    multiset<long long> A;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int operation;
        cin >> operation;
        if (operation == 1)
        {
            long long x;
            cin >> x;
            A.insert(x);
        }
        else if (operation == 2)
        {
            long long x, k;
            cin >> x >> k;
            auto it = A.upper_bound(x);
            bool find = true;
            for (int j = 0; j < k; j++)
            {
                if (it == A.begin())
                {
                    find = false;
                    break;
                }
                it--;
            }
            if (find)
                cout << *it << endl;
            else
                cout << "-1" << endl;
        }
        else
        {
            long long x, k;
            cin >> x >> k;
            auto it = A.lower_bound(x);
            bool find = true;
            for (int j = 1; j < k; j++)
            {
                if (it == A.end())
                {
                    find = false;
                    break;
                }
                it++;
            }
            if (it == A.end())
                find = false;
            if (find)
                cout << *it << endl;
            else
                cout << "-1" << endl;
        }
    }
    return 0;
}