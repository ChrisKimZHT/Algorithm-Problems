#include <stdio.h>

int main(void)
{
	int num, N, guess, count = 0;
	scanf("%d%d", &num, &N);
	while (scanf("%d", &guess) != EOF)
	{
		if (guess < 0)
		{
			printf("Game Over\n");
			break;
		}
		count++;
		if (guess < num)
		{
			printf("Too small\n");
		}
		else if (guess > num)
		{
			printf("Too big\n");
		}
		else if (guess == num)
		{
			if (count == 1)
			{
				printf("Bingo!\n");
			}
			else if (count <= 3)
			{
				printf("Lucky You!\n");
			}
			else if (count <= N)
			{
				printf("Good Guess!\n");
			}
			else
			{
				printf("Game Over\n");
			}
			break;
		}
	}
	return 0;
}