#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        string str;
        cin >> str;
        int cnt_s1 = 0;
        for (int i = 0; i < str.size(); i++)
            if (str[i] == '1')
                cnt_s1++;
        int cnt_1 = 0, cnt_0 = 0;
        for (int i = 0; i < K; i++)
        {
            if (str[i] == '0')
                cnt_0++;
            else if (str[i] == '1')
                cnt_1++;
        }
        bool flag = false;
        for (int i = 0; i + K <= str.size(); i++)
        {
            if (cnt_1 == cnt_s1 && cnt_0 == 0)
            {
                if (!flag)
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (str[i] == '1')
                cnt_1--;
            else if (str[i] == '0')
                cnt_0--;
            if (i + K < str.size() && str[i + K] == '1')
                cnt_1++;
            else if (i + K < str.size() && str[i + K] == '0')
                cnt_0++;
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}