#include <bits/stdc++.h>
#define int long long
//#define INF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define FOR(i, x, y) for (int i = x; i <= y; i++)
using namespace std;
int lowbit(int x)
{
    return -x & x;
}
const int mod = 998244353;
// const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int M = 6e5 + 5;
int ksm(int x, int y, int mod1 = mod)
{
    int res = 1;
    x %= mod1;
    while (y > 0)
    {
        if (y & 1)
        {
            res = res * x % mod1;
        }
        y >>= 1;
        x = (x * x) % mod1;
    }
    return res;
}
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}
typedef pair<int, int> pii;

map<string,int>mp;
void solve()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		int t;cin>>t;
		while(t--)
		{
			string s;cin>>s;
			mp[s]++;
		}
	}
	int res=0;
	set<string>st;
	for(auto it:mp)
	{
		if(it.second==n)
		{
			res++;
			st.insert(it.first);
		}
	}
	cout<<res<<"\n";
	for(auto it:st)
	{
		cout<<it<<"\n";
	}
}

signed main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
