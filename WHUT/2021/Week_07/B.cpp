#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
#include <string.h>

using namespace std;

int main(void)
{
	stack<string> forward;
	stack<string> backward;
	char command[10];
	char website[100];
	char current[100] = "http://www.acm.org/";
	while (1)
	{
		scanf("%s", command);
		if (command[0] == 'Q')
		{
			return 0;
		}
		else if (command[0] == 'V')
		{
			scanf("%s", website);
			backward.push(current);
			while (forward.empty() != 1)
			{
				forward.pop();
			}
			strcpy(current, website);
			printf("%s\n", current);
		}
		else if (command[0] == 'B')
		{
			if (backward.empty() != 1)
			{
				forward.push(current);
				strcpy(current, (backward.top()).c_str());
				backward.pop();
				printf("%s\n", current);
			}
			else
			{
				printf("Ignored\n");
			}
		}
		else if (command[0] == 'F')
		{
			if (forward.empty() != 1)
			{
				backward.push(current);
				strcpy(current, (forward.top()).c_str());
				forward.pop();
				printf("%s\n", current);
			}
			else
			{
				printf("Ignored\n");
			}
		}
	}
}