#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int N;

struct SUBMISSION
{
    int id;
    string content;
    int score;
};

vector<SUBMISSION> sub;
map<string, bool> is_subed;

bool cmp(SUBMISSION a, SUBMISSION b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else
        return a.id < b.id;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        string str;
        int sco;
        cin >> str >> sco;
        if (!is_subed[str])
        {
            sub.push_back({i, str, sco});
            is_subed[str] = true;
        }
    }
    sort(sub.begin(), sub.end(), cmp);
    cout << sub[0].id << endl;
    return 0;
}