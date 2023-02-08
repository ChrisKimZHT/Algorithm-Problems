#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int maxi, midi, mini;
		cin >> maxi >> midi >> mini;
		if (maxi < mini)
			swap(maxi, mini);
		if (midi < mini)
			swap(mini, midi);
		if (maxi < midi)
			swap(maxi, midi);
		int ans = 0;
		ans += min(min(maxi / 3, midi / 2), mini / 1);
		ans += min(min(maxi / 3, midi / 1), mini / 2);
		ans += min(min(maxi / 2, midi / 3), mini / 1);
		ans += min(min(maxi / 2, midi / 1), mini / 3);
		ans += min(min(maxi / 1, midi / 3), mini / 2);
		ans += min(min(maxi / 1, midi / 2), mini / 3);
		cout << ans << endl;
	}
	return 0;
}