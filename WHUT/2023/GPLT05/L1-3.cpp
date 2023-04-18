#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int restrict, company, age1, age2;
    cin >> restrict >> company >> age1 >> age2;
    if (age1 >= restrict && age2 >= restrict)
    {
        cout << age1 << "-Y " << age2 << "-Y" << endl;
        cout << "huan ying ru guan" << endl;
    }
    else if (age1 < restrict && age2 >= company)
    {
        cout << age1 << "-Y " << age2 << "-Y" << endl;
        cout << "qing 2 zhao gu hao 1" << endl;
    }
    else if (age1 >= company & age2 < restrict)
    {
        cout << age1 << "-Y " << age2 << "-Y" << endl;
        cout << "qing 1 zhao gu hao 2" << endl;
    }
    else if (age1 < restrict && age2 >= restrict)
    {
        cout << age1 << "-N " << age2 << "-Y" << endl;
        cout << "2: huan ying ru guan" << endl;
    }
    else if (age1 >= restrict && age2 < restrict)
    {
        cout << age1 << "-Y " << age2 << "-N" << endl;
        cout << "1: huan ying ru guan" << endl;
    }
    else
    {
        cout << age1 << "-N " << age2 << "-N" << endl;
        cout << "zhang da zai lai ba" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
