#include<bits/stdc++.h>
#define int long long
//#define INF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define FOR(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int lowbit(int x) { return -x & x; } 
const int mod = 998244353;
//const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int M = 6e5 + 5;
int ksm(int x, int y, int mod1 = mod) {  
    int res = 1;
    x %= mod1;
    while (y > 0) {
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


int a[N];
string s1[N];
string s2[N];
int b[N];
int c[N];
void solve()
{
	int n,m,q;cin>>n>>m>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>s1[i]>>a[i]>>s2[i];
	}
	int off=0,on=0;
	int ans=0;
	for(int i=q;i>=1;i--)
	{
		if(s1[i]=="column")
		{
			if(c[a[i]]==0)
			{
				if(s2[i]=="on")c[a[i]]=1;
				else c[a[i]]=-1;
			}else continue;
			if(c[a[i]]==1)on++;
			else off++;
		}else
		{
			if(b[a[i]]==0)
			{
				if(s2[i]=="on")b[a[i]]=1;
				else b[a[i]]=-1;
			}else continue;
			if(b[a[i]]==1)ans+=m-off;
			else ans+=on;
		}
		//cout<<off<<"\n";
		//cout<<ans<<"\n";
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)ans+=on;
	}
	cout<<ans<<"\n";
}
signed main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}

