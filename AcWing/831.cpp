#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
int lens1, lens2;
char s1[MAXN], s2[MAXN];
int nxt[MAXN];

void getnext(void)
{
    nxt[0] = -1;
    int i = 0, j = -1;
    while (i < lens2)
    {
        if (j == -1 || s2[i] == s2[j])
        {
            ++i;
            ++j;
            nxt[i] = j;
        }
        else
        {
            j = nxt[j];
        }
    }
}

void kmp(void)
{
    int i = 0, j = 0;
    while (i < lens1)
    {
        if (j == -1 || s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            j = nxt[j];
        }
        if (j == lens2)
        {
            printf("%d ", i - j);
        }
    }
}

int main()
{
    cin >> lens2 >> s2 >> lens1 >> s1;
    getnext();
    kmp();
    return 0;
}