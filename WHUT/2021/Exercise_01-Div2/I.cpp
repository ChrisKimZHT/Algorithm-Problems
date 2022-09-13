#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cuchar>
#include <cwchar>
#include <cwctype>
#endif
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#if __cplusplus >= 201402L
#include <shared_mutex>
#endif
#if __cplusplus >= 201703L
#include <charconv>
#include <filesystem>
#endif

using namespace std;

int N, M;
int money[100010];

int cnt(int);

int main(void)
{
	cin >> N >> M;
	int sumi = 0, maxi = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> money[i];
		sumi += money[i];
		maxi = max(maxi, money[i]);
	}
	int l = maxi, r = sumi;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (cnt(mid) > M)
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	cout << l << endl;
	/*while (1)
	{
		int tmp;
		cin >> tmp;
		cout << cnt(tmp) << endl;
	}*/
	return 0;
}

int cnt(int x)
{
	int result = 1;
	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		if (tmp + money[i] > x)
		{
			result++;
			tmp = money[i];
		}
		else
		{
			tmp += money[i];
		}
	}
	return result;
}