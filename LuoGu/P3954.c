#include <stdio.h>

int main(void)
{
	int A, B, C, score;
	scanf("%d%d%d", &A, &B, &C);
	score = .2 * A + .3 * B + .5 * C;
	printf("%d", score);
	return 0;
}