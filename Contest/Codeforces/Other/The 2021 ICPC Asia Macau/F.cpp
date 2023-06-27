#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
const int N=5e5+10;


int vis[N];
int a[N];
void solve()
{
	int n;cin>>n;
	priority_queue<pii,vector<pii>,less<pii> >q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		q.push({a[i],i});
	}
	int cnt=0;
	int tt=0;
	while(tt<=n)
	{
		pii t=q.top();
		if(t.first+cnt>=n-1)
		{
			q.pop();
			q.push({t.first-1-(n-1),t.second});
			cnt++;
		}else
		{
			break;
		}
		tt++;
	}
	if(tt>n)
	{
		cout<<"Recurrent\n";
	}else
	{
		while(q.size())
		{
			pii t=q.top();
			q.pop();
			a[t.second]=t.first+cnt;
		}
		for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];
	}
	
}



signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
}