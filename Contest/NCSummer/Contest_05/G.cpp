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
int b[N][5];
int n,k;
bool check(int i,int x)
{
	for(int j=1;j<=3;j++)
	{
		if(b[x][j]-b[i-1][j]<1)return false;
	}
	return (b[x][4]-b[i-1][4]>=k);
}


void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=4;j++)
		{
			b[i][j]=b[i-1][j];
		}
		b[i][a[i]]++;
	}
	/*for(int j=1;j<=4;j++)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<b[i][j]<<" \n"[i==n];
		}
	}*/
	int ans=INF;
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(check(i,mid))r=mid;
			else l=mid+1;
			//cout<<mid<<"\n";
		}
		if(check(i,l))ans=min(l-i+1,ans);
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

