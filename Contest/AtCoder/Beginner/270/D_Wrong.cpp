#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> A;

int main()
{
    cin >> N >> K;
    A.resize(K);
    for (int i = 0; i < K; i++)
        cin >> A[i];
    int tak = 0, aok = 0;
    for (int i = 1;; i++)
    {
        if (!N)
            break;
        while (A.size() && A.back() > N)
            A.pop_back();
        if (i % 2)
        {
            tak += A.back();
            N -= A.back();
        }
        else
        {
            aok += A.back();
            N -= A.back();
        }
    }
    cout << tak << endl;
    return 0;
}