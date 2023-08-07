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

vector<string>st[405][405];
int a[405]; //长度



void solve()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		string t;cin>>t;
		int len=t.length();
		if(a[len]==0)
		{
			st[len][++a[len]].push_back(t);
		}else
		{
			for(int i=1;i<=a[len];i++)
			{
				int flag=1,flag1=0,flag2=0;
				for(auto it:st[len][i])
				{
					
					for(int i=0;i<it.length();i++)
					{
						if(it[i]!=t[i]&&it[i]!='?'&&t[i]!='?')
						{
							flag=0;
							break;
						}else if(it[i]=='?'&&t[i]!='?')
						{
							flag1=1;
						}else if(it[i]!='?'&&t[i]=='?')
						{
							flag2=1;
						}
					}
					if(flag==0)break;
					
				}
				if(flag&&flag1&&flag2)st[len][i].push_back(t);
				else if(flag&&flag2)
				{
					vector<int>v;
					for(int j=0;j<st[len][i].size();j++)
					{
						string it=st[len][i][j];
						int f1=0,f2=0;
						for(int i=0;i<it.length();i++)
						{
							if(it[i]=='?'&&t[i]!='?')
							{
								f1=1;
							}else if(it[i]!='?'&&t[i]=='?')
							{
								f2=1;
							}
						}
						if(!f1&&f2)v.push_back(j);
					}
					while(v.size())
					{
						st[len][i].erase(st[len][i].begin()+v.back());
						v.pop_back();
					}
					st[len][i].push_back(t);
					
				}else if(flag&&flag1)
				{
					break;
				}
				else if(flag&&!flag1&&!flag2)
				{
					break;
				}
				else
				{
					if(i==a[len])st[len][++a[len]].push_back(t);
					
				}
			}
		}
	}
	
	for(int i=1;i<=4;i++)cout<<a[i]<<" \n"[i==4];
	
	for(int i=1;i<=a[4];i++)
	{
		cout<<i<<":\n";
		for(auto it:st[4][i])
		{
			cout<<it<<"\n";
		}
	}
	
	int ans=0;
	for(int i=1;i<=400;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			for(auto it:st[i][j])
			{
				int res=1;
				for(int k=0;k<it.length();k++)
				{
					if(it[k]=='?')res=(res*2)%mod;
				}
				ans=(ans+res)%mod;
			}
			int x=st[i][j].size();
			ans=((ans-max(0LL,(x-1)))%mod+mod)%mod;
			//cout<<ans<<"\n";
		}
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

