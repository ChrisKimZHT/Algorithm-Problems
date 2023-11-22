#include <stdio.h>
#include <string.h>
#define MAXN 210
#define MAXM 110

int n;
char sig[MAXM][MAXN];
char name[MAXM][MAXN];
int cnt[MAXM];

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", name[i]);
        scanf("%s", sig[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int offset = 0;
        while (1)
        {
            char *p = strstr(sig[i] + offset, "sos");
            if (p == NULL)
                break;
            int pos = p - sig[i];
            cnt[i]++;
            offset = pos + 1;
        }
        // int len = strlen(sig[i]);
        // for (int j = 0; j < len - 2; j++)
        // {
        //     if (sig[i][j] == 's' &&
        //         sig[i][j + 1] == 'o' &&
        //         sig[i][j + 2] == 's')
        //         cnt[i]++;
        // }
    }
    int max_ans = 0;
    for (int i = 0; i < n; i++)
        max_ans = max_ans > cnt[i] ? max_ans : cnt[i];
    for (int i = 0; i < n; i++)
        if (max_ans == cnt[i])
            printf("%s ", name[i]);
    printf("\n%d\n", max_ans);
    return 0;
}