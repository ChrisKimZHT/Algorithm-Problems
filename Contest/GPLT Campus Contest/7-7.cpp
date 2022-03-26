#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct SCORE
{
    int id;
    int point[15];
    int time[15];
    bool valid[15];
    int s_a, s_1, s_2, s_3;
    int max_t;
} student[5010];

bool cmp(SCORE a, SCORE b)
{
    if (a.s_a != b.s_a)
        return a.s_a > b.s_a;
    else if (a.s_3 != b.s_3)
        return a.s_3 > b.s_3;
    else if (a.s_2 != b.s_2)
        return a.s_2 > b.s_2;
    else if (a.s_1 != b.s_1)
        return a.s_1 > b.s_1;
    else
        return a.max_t < b.max_t;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        student[i].id = i + 1;
        for (int j = 0; j < 15; j++)
        {
            cin >> student[i].point[j];
        }
        int sum_1 = 0;
        for (int j = 0; j < 8; j++)
        {
            sum_1 += student[i].point[j];
            student[i].valid[j] = true;
        }
        student[i].s_1 = sum_1;
        int sum_2 = 0;
        if (sum_1 > 80)
        {
            for (int j = 8; j < 12; j++)
            {
                sum_2 += student[i].point[j];
                student[i].valid[j] = true;
            }
            student[i].s_2 = sum_2;
        }
        else
        {
            student[i].s_2 = 0;
        }
        int sum_3 = 0;
        if (sum_2 > 40)
        {
            for (int j = 12; j < 15; j++)
            {
                sum_3 += student[i].point[j];
                student[i].valid[j] = true;
            }
            student[i].s_3 = sum_3;
        }
        else
        {
            student[i].s_3 = 0;
        }
        student[i].s_a = student[i].s_1 + student[i].s_2 + student[i].s_3;
    }
    for (int i = 0; i < n; i++)
    {
        student[i].max_t = 0;
        for (int j = 0; j < 15; j++)
        {
            cin >> student[i].time[j];
            if (student[i].valid[j])
                student[i].max_t = max(student[i].max_t, student[i].time[j]);
        }
    }
    sort(student, student + n, cmp);
    for (int i = 0; i < n; i++)
        cout << student[i].id << ' ';
    cout << endl;
    return 0;
}