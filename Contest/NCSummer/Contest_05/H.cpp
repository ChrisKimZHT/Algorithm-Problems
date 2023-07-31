#include<bits/stdc++.h>
#define int long long
//#define INF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define FOR(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int lowbit(int x) { return -x & x; } 
const int mod = 998244353;
//const int mod = 1e9 + 7;
const int N = 1e5 + 10;
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


int dp[205][2];
int f[205][205][205];
int a[205],b[205];
int sz[N];

void solve()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=200;k>=0;k--)
			{
				f[k][i][j]=f[k][i][j-1];
				if(k>=a[j])f[k][i][j]=max(f[k][i][j],f[k-a[j]][i][j-1]+b[j]);
			}
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			cout<<i<<"-"<<j<<":";
			for(int k=1;k<=10;k++)
			{
				cout<<f[k][i][j]<<" \n"[k==10];
			}
		}
	}*/
	
	for(int i=1;i<=m;i++)cin>>sz[i];
	int op=0;
	for(int i=1;i<=n;i++)dp[i][0]=f[sz[max(0LL,m-n)+1]][1][i];
	//for(int i=1;i<=n;i++)cout<<dp[i][op]<<" \n"[i==n];
	op^=1;
	for(int i=max(0LL,m-n)+2;i<=m;i++)
	{
		for(int k=1;k<=n;k++)
		{
			dp[k][op]=dp[k][op^1];
			for(int j=k-1;j>=0;j--)
			{
				dp[k][op]=max(dp[k][op],dp[j][op^1]+f[sz[i]][j+1][k]);
			}
		}
		
		/*for(int j=1;j<=n;j++)
		{
			cout<<dp[j][op]<<" \n"[j==n];
		}*/
		op^=1;
		for(int j=0;j<=200;j++)dp[j][op]=0;
	}
	cout<<dp[n][op^1]<<"\n";
	
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

