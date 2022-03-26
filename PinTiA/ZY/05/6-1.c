#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stud_node
{
	int num;
	char name[20];
	int score;
	struct stud_node *next;
};
struct stud_node *head, *tail;

void input();

int main()
{
	struct stud_node *p;

	head = tail = NULL;
	input();
	for (p = head; p != NULL; p = p->next)
		printf("%d %s %d\n", p->num, p->name, p->score);

	return 0;
}

/* 你的代码将被嵌在这里 */
void input()
{
	struct stud_node *q;
	while (1)
	{
		q = (struct stud_node *)malloc(sizeof(struct stud_node));
		scanf("%d", &q->num);
		if (!q->num)
			break;
		scanf("%s%d", q->name, &q->score);
		if (head == NULL)
			head = q;
		else
			tail->next = q;
		tail = q;
	}
}