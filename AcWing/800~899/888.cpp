#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5010;
bool is_prime[MAXN];
int prime[MAXN], idx;
int npow[MAXN];

void init_prime(int x)
{
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= x; i++)
    {
        if (is_prime[i])
            prime[idx++] = i;
        for (int j = 0; i * prime[j] <= x && j < idx; j++)
        {
            is_prime[i * prime[j]] = false;
            if (!(i % prime[j]))
                break;
        }
    }
}

int get(int x, int p)
{
    int res = 0;
    while (x)
    {
        res += x / p;
        x /= p;
    }
    return res;
}

vector<int> mul(vector<int> &a, int b)
{
    vector<int> ans;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i] * b;
        ans.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        ans.push_back(t % 10);
        t /= 10;
    }
    return ans;
}

int main()
{
    int a, b;
    cin >> a >> b;
    init_prime(a);
    for (int i = 0; i < idx; i++)
        npow[i] = get(a, prime[i]) - get(b, prime[i]) - get(a - b, prime[i]);
    vector<int> ans;
    ans.push_back(1);
    for (int i = 0; i < idx; i++)
        for (int j = 0; j < npow[i]; j++)
            ans = mul(ans, prime[i]);
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    cout << endl;
    return 0;
}