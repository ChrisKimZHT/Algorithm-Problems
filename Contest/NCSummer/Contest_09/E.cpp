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

struct node
{
	int sx,sy,a;
};

vector<node>ans;
void dfs(int sx,int sy,int x,int y)
{
	//cout<<sx<<" "<<sy<<" "<<x<<" "<<y<<"\n";
	if(x==1&&y==1)
	{
		ans.push_back({sx,sy,1});
		return;
	}
	if(x==y)
	{
		ans.push_back({sx,sy,x});
	}
	else if(x>y)
	{
		for(int i=1;i<=x/y;i++)
		{
			ans.push_back({sx+(i-1)*y,sy,y});
		}
		if(x%y)dfs(sx+(x/y)*y,sy,x%y,y);
	}else
	{
		for(int i=1;i<=y/x;i++)
		{
			ans.push_back({sx,sy+(i-1)*x,x});
		}
		if(y%x)dfs(sx,sy+(y/x)*x,x,y%x);
	}
}


void solve()
{
	ans.clear();
	int x,y;cin>>x>>y;
	dfs(0,0,x,y);
	cout<<"YES\n";
	cout<<ans.size()<<"\n";
	for(auto it:ans)
	{
		cout<<it.sx<<" "<<it.sy<<" "<<it.a<<"\n";
	}
}

signed main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
