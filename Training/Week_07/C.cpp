#include <iostream>
#include <queue>

using namespace std;

int whichteam[1000000];

int main(void)
{
	for (int scenario = 1;; scenario++)
	{
		int t;
		char command[10];
		queue<int> eleq[1000];
		queue<int> temq;
		cin >> t;
		if (t == 0)
		{
			return 0;
		}
		cout << "Scenario #" << scenario << endl;
		for (int i = 0; i < t; i++)
		{
			int nelem;
			cin >> nelem;
			for (int j = 0; j < nelem; j++)
			{
				int elem;
				cin >> elem;
				whichteam[elem] = i;
			}
		}
		while (1)
		{
			cin >> command;
			if (command[0] == 'S')
			{
				break;
			}
			else if (command[0] == 'E')
			{
				int teammate;
				cin >> teammate;
				if (eleq[whichteam[teammate]].empty() == 1)
				{
					temq.push(whichteam[teammate]);
				}
				eleq[whichteam[teammate]].push(teammate);
			}
			else if (command[0] == 'D')
			{
				cout << eleq[temq.front()].front() << endl;
				eleq[temq.front()].pop();
				if (eleq[temq.front()].empty() == 1)
				{
					temq.pop();
				}
			}
		}
		cout << endl;
	}
}