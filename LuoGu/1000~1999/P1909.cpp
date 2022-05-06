#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int need, a, b, c;
	int n1, n2, n3, c1, c2, c3;
	scanf("%d%d%d%d%d%d%d", &need, &n1, &c1, &n2, &c2, &n3, &c3);
	a = ceil(1.0 * need / n1) * c1;
	b = ceil(1.0 * need / n2) * c2;
	c = ceil(1.0 * need / n3) * c3;
	printf("%d", min(a, min(b, c)));
	return 0;
}