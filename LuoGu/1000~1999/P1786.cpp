#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> r2i{
    {"BangZhu", 0},
    {"FuBangZhu", 1},
    {"HuFa", 2},
    {"ZhangLao", 3},
    {"TangZhu", 4},
    {"JingYing", 5},
    {"BangZhong", 6}};
unordered_map<int, string> i2r{
    {0, "BangZhu"},
    {1, "FuBangZhu"},
    {2, "HuFa"},
    {3, "ZhangLao"},
    {4, "TangZhu"},
    {5, "JingYing"},
    {6, "BangZhong"}};
struct Member
{
    int id;
    string name;
    int rank;
    int exp;
    int level;
};
vector<Member> group;
int n;

bool cmp_1(Member a, Member b)
{
    if (a.exp != b.exp)
        return a.exp > b.exp;
    return a.id < b.id;
}

bool cmp_2(Member a, Member b)
{
    if (a.rank != b.rank)
        return a.rank < b.rank;
    if (a.level != b.level)
        return a.level > b.level;
    return a.id < b.id;
}

void upd_rank()
{
    for (int i = 0; i < group.size(); i++)
    {
        if (i == 0)
            group[i].rank = 0;
        else if (1 <= i && i <= 2)
            group[i].rank = 1;
        else if (3 <= i && i <= 4)
            group[i].rank = 2;
        else if (5 <= i && i <= 8)
            group[i].rank = 3;
        else if (9 <= i && i <= 15)
            group[i].rank = 4;
        else if (16 <= i && i <= 40)
            group[i].rank = 5;
        else
            group[i].rank = 6;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name, rank;
        int exp, level;
        cin >> name >> rank >> exp >> level;
        group.push_back({i, name, r2i[rank], exp, level});
    }
    sort(group.begin() + 3, group.end(), cmp_1);
    upd_rank();
    sort(group.begin(), group.end(), cmp_2);
    for (auto &member : group)
        cout << member.name << ' ' << i2r[member.rank] << ' ' << member.level << endl;
    return 0;
}