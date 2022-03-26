#include <stdio.h>
#include <stdlib.h>

struct stud_node
{
	int num;
	char name[20];
	int score;
	struct stud_node *next;
};

struct stud_node *createlist();
struct stud_node *deletelist(struct stud_node *head, int min_score);

int main()
{
	int min_score;
	struct stud_node *p, *head = NULL;

	head = createlist();
	scanf("%d", &min_score);
	head = deletelist(head, min_score);
	for (p = head; p != NULL; p = p->next)
		printf("%d %s %d\n", p->num, p->name, p->score);

	return 0;
}

/* 你的代码将被嵌在这里 */
struct stud_node *createlist()
{
	struct stud_node *head = NULL, *tail = NULL;
	while (1)
	{
		struct stud_node *a = (struct stud_node *)malloc(sizeof(struct stud_node));
		scanf("%d", &a->num);
		if (!a->num)
			break;
		scanf("%s%d", a->name, &a->score);
		a->next = NULL;
		if (head == NULL)
			head = a;
		else
			tail->next = a;
		tail = a;
	}
	return head;
}

struct stud_node *deletelist(struct stud_node *head, int min_score)
{
	if (head == NULL)
		return NULL;
	struct stud_node *p, *part1, *part2;
	part2 = p = head;
	int flag = 0;
	for (; p != NULL; p = p->next)
	{
		if (head->score < min_score && flag == 0)
		{
			head = head->next;
			continue;
		} //考虑第一种情况，即开头的数据就需要删除，此时还不需要辅助指针part1、part2.如果删去后，第二个数据仍然不满足题意，则还需要进入此分支。
		flag = 1;
		if (p->score < min_score && flag == 1)
		{
			part1->next = part2->next;
			free(part2);
			part2 = part1->next;
			continue;
		} //前面已经有满足题意的数据时，程序将永远进入此分支进行判断并采用辅助指针
		part1 = p;
		part2 = p->next; //没有什么特殊需要处理时，辅助指针向下滚动。
	}
	return head;
}