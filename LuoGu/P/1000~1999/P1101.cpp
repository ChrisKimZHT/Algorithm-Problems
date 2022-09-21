#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
const char word[8] = "yizhong";
char mat[MAXN][MAXN];
bool st[MAXN][MAXN];
int n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> mat[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 右
            bool flag = true;
            for (int k = 0; k < 7; k++)
            {
                if (j + k >= n || mat[i][j + k] != word[k])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                for (int k = 0; k < 7; k++)
                    st[i][j + k] = true;
            // 左
            flag = true;
            for (int k = 0; k < 7; k++)
            {
                if (j - k < 0 || mat[i][j - k] != word[k])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                for (int k = 0; k < 7; k++)
                    st[i][j - k] = true;
            // 下
            flag = true;
            for (int k = 0; k < 7; k++)
            {
                if (i + k >= n || mat[i + k][j] != word[k])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                for (int k = 0; k < 7; k++)
                    st[i + k][j] = true;
            // 上
            flag = true;
            for (int k = 0; k < 7; k++)
            {
                if (i + k < 0 || mat[i - k][j] != word[k])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                for (int k = 0; k < 7; k++)
                    st[i - k][j] = true;
            // 右下
            flag = true;
            for (int k = 0; k < 7; k++)
            {
                if (i + k >= n || j + k >= n || mat[i + k][j + k] != word[k])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                for (int k = 0; k < 7; k++)
                    st[i + k][j + k] = true;
            // 左下
            flag = true;
            for (int k = 0; k < 7; k++)
            {
                if (i + k >= n || j - k < 0 || mat[i + k][j - k] != word[k])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                for (int k = 0; k < 7; k++)
                    st[i + k][j - k] = true;
            // 右上
            flag = true;
            for (int k = 0; k < 7; k++)
            {
                if (i - k < 0 || j + k >= n || mat[i - k][j + k] != word[k])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                for (int k = 0; k < 7; k++)
                    st[i - k][j + k] = true;
            // 左上
            flag = true;
            for (int k = 0; k < 7; k++)
            {
                if (i - k < 0 || j - k < 0 || mat[i - k][j - k] != word[k])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                for (int k = 0; k < 7; k++)
                    st[i - k][j - k] = true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (st[i][j])
                cout << mat[i][j];
            else
                cout << '*';
        }
        cout << endl;
    }
    return 0;
}