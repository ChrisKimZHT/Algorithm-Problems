#include <iostream>

using namespace std;

const int SIZE = 1e5 + 20;

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, S;
		cin >> N >> S;
		long long presum[SIZE];
		for (int i = 1; i <= N; i++)
		{
			cin >> presum[i];
			presum[i] += presum[i - 1];
		}
		int l = 0, r = 0;
		int ans = INT32_MAX;
		bool is_ans = false;
		while (r <= N)
		{
			if (presum[r] - presum[l] < S)
			{
				r++;
			}
			else
			{
				ans = min(ans, r - l);
				is_ans = true;
				l++;
			}
		}
		cout << int(is_ans ? ans : 0) << endl;
	}
	return 0;
}