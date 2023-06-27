#include <bits/stdc++.h>
using namespace std;
 
#define int long long
const int N=1e5+10;
int t[N];
int find(int x)
{
	return t[x]==x?x:t[x]=find(t[x]);
}
 
 
typedef pair<int,int> pii;
 
vector<pii>e[N];
 
int x[N],y[N],oo[N];
 
int tar;
vector<int>ans;
bool dfs(int x,int pre)
{
	if(x==tar)
	{
		return true;
	}
	for(auto it:e[x])
	{
		if(it.first==pre)continue;
		if(dfs(it.first,x))
		{
			ans.push_back(it.second);
			return true;
		}
	}
	return false;
}
 
void solve()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		t[i]=i;
		e[i].clear();
	}
	ans.clear();
	int cnt=-1;
	for(int i=1;i<=m;i++)
	{
		cin>>x[i]>>y[i];
		oo[i]=i;
	}
	
	for(int i=1;i<=m;i++)
	{
		int a=find(x[i]),b=find(y[i]);
		if(a!=b)
		{
			t[a]=b;
		}else
		{
			cnt=i;
			break;
		}
	}
	
	if(cnt==-1)
	{
		cout<<cnt<<"\n";
		return;
	}
	
	for(int i=1;i<cnt;i++)
	{
		e[x[i]].push_back({y[i],oo[i]});
		e[y[i]].push_back({x[i],oo[i]});
	}
	
	tar=y[cnt];
	dfs(x[cnt],0);
	ans.push_back(oo[cnt]);
	sort(ans.begin(),ans.end());
	int z=ans.back();
	for(auto it:ans)
	{
		cout<<it;
		if(it!=z)cout<<" ";
		else cout<<"\n";
	}
}
 
 
 
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
}