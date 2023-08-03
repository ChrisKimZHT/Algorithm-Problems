#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size())
        return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--)
        if (A[i] != B[i])
            return A[i] > B[i];
    return true;
}

vector<int> add(vector<int> &A, vector<int> &B)
{
    if (B.size() > A.size())
        return add(B, A);
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t = t > 9 ? 1 : 0;
    }
    if (t)
        C.push_back(1);
    return C;
}

vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if (i < B.size())
            t -= B[i];
        C.push_back((t + 10) % 10);
        t = t < 0 ? 1 : 0;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size())
            t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

int main()
{
    /* string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0'); */

    // BigInt + BigInt
    /*
    vector<int> C = add(A, B);
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl;
    */

    // BigInt - BigInte
    /* if (cmp(A, B))
    {
        vector<int> C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i--)
            cout << C[i];
        cout << endl;
    }
    else
    {
        vector<int> C = sub(B, A);
        cout << '-';
        for (int i = C.size() - 1; i >= 0; i--)
            cout << C[i];
        cout << endl;
    } */

    /* string a;
    int b;
    vector<int> A;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0'); */

    // BitInt * int
    /* vector<int> C = mul(A, b);
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl;
    return 0; */
    
    // BitInt / int
    /* int r;
    vector<int> C = div(A, b, r);
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl
         << r << endl;
    return 0; */
}