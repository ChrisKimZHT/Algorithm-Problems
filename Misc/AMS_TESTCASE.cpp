#include <bits/stdc++.h>

using namespace std;

int main()
{
    ofstream CardData;
    CardData.open("CardData.txt", ios::out);
    for (int i = 1; i <= 100000; i++)
    {
        CardData << "Test" << i << " 000000 0 1600000000 1600000000 1600000000 0 0 100 1" << endl;
    }
    CardData.close();
    return 0;
}