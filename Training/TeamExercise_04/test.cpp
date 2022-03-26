#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
int const MAX = 1e6 + 10;
int p[MAX];	 //用于存素数
bool u[MAX]; // u[i]标记数字i是否为素数
int num, cnt;
ll a, b, tmp;

void get_prime()
{
	memset(u, false, sizeof(u));
	for (int i = 2; i <= sqrt(MAX); i++)
		if (!u[i])
			for (int j = i * i; j <= MAX; j += i)
				u[j] = true;
	for (int i = 2; i <= MAX; i++)
		if (!u[i])
			p[cnt++] = i;
}

//唯一分解定理的正体
void cal()
{
	for (int i = 0; i < cnt && p[i] <= sqrt(tmp); i++)
	{
		int cc = 0;
		while (tmp % p[i] == 0)
		{
			cc++;
			tmp /= p[i];
		}
		num *= (cc + 1);
	}
	if (tmp > 1) //如果tmp不能被整分，说明还有一个素数是它的约数，此时cc=1
		num *= 2;
}

int main()
{
	int T;
	scanf("%d", &T);
	cnt = 0;
	get_prime();
	for (int ca = 1; ca <= T; ca++)
	{
		scanf("%lld %lld", &a, &b);
		if (a < b * b)
			printf("Case %d: 0\n", ca);
		else
		{
			num = 1;
			tmp = a;
			cal();
			num /= 2;
			for (int i = 1; i < b; i++)
				if (a % i == 0)
					num--;
			printf("Case %d: %d\n", ca, num);
		}
	}
}