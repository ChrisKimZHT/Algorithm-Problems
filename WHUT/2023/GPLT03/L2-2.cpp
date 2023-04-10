#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

struct Data
{
    int a;
    string name;
    string id;
    int status;
    string time;
    int hour;
    int minute;

    Data(int a, string name, string id, int status, string time)
    {
        this->a = a;
        this->name = name;
        this->id = id;
        this->status = status;
        this->time = time;
        this->hour = stoi(time.substr(0, 2));
        this->minute = stoi(time.substr(3, 2));
    }

    bool operator<(const Data &x) const
    {
        if (hour != x.hour)
            return hour < x.hour;
        if (minute != x.minute)
            return minute < x.minute;
        return a < x.a;
    }
};

bool check_id(string id)
{
    if (id.size() != 18)
        return false;
    for (int i = 0; i < id.size(); i++)
        if (!isdigit(id[i]))
            return false;
    return true;
}

void solve()
{
    int D, P;
    cin >> D >> P;
    map<string, int> last;
    vector<pair<string, string>> not_good;
    set<string> st;
    for (int i = 1; i <= D; i++)
    {
        int T, S;
        cin >> T >> S;
        vector<Data> vec;
        for (int j = 1; j <= T; j++)
        {
            string name, id, time;
            int status;
            cin >> name >> id >> status >> time;
            if (!check_id(id))
                continue;
            if (status == 1 && st.count(id) == 0)
            {
                st.insert(id);
                not_good.push_back({name, id});
            }
            vec.push_back(Data(j, name, id, status, time));
        }
        sort(vec.begin(), vec.end());
        for (int j = 0; j < vec.size(); j++)
        {
            if (S <= 0)
                break;
            string &id = vec[j].id;
            if (last.count(id) == 0)
            {
                last[id] = i;
                cout << vec[j].name << ' ' << id << endl;
                S--;
                continue;
            }
            int &lst = last[id];
            if (lst + P + 1 <= i)
            {
                lst = i;
                cout << vec[j].name << ' ' << id << endl;
                S--;
            }
        }
    }
    for (auto ele : not_good)
        cout << ele.first << ' ' << ele.second << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}