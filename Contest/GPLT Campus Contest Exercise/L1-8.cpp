#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;
    map<int, int> team_score;
    while (N--)
    {
        int team_id, member_id, grade;
        scanf("%d-%d %d", &team_id, &member_id, &grade);
        team_score[team_id] += grade;
    }
    int max_score = 0, max_team = 0;
    for (auto it = team_score.begin(); it != team_score.end(); ++it)
    {
        if (it->second > max_score)
        {
            max_score = it->second;
            max_team = it->first;
        }
    }
    cout << max_team << ' ' << max_score << endl;
}