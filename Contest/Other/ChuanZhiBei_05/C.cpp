#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> file;
    string line;
    while (getline(cin, line))
        file.push_back(line);
    int line_cnt = file.size();
    int line_cnt_width = 1, t = 10;
    while (line_cnt / t)
    {
        line_cnt_width++;
        t *= 10;
    }
    for (int i = 0; i < line_cnt; i++)
        cout << setw(line_cnt_width) << i + 1 << ' ' << file[i] << endl;
    return 0;
}