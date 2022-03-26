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
// 提交前记得改 SIZE
#define SIZE 1000010
// #define INT32_MAX 2147483647
// #define INT32_MIN (-2147483647 - 1)

using namespace std;

int value[SIZE], maxv[SIZE], minv[SIZE];

int main(void)
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &value[i]);
	}
	map<int, int> num;
	for (int i = 0; i < k; i++)
	{
		num[value[i]]++;
	}
	minv[k - 1] = num.begin()->first;
	maxv[k - 1] = num.rbegin()->first;
	for (int i = k; i < n; i++)
	{
		num[value[i]]++;
		num[value[i - k]]--;
		if (num[value[i - k]] == 0)
		{
			num.erase(num.find(value[i - k]));
		}
		minv[i] = num.begin()->first;
		maxv[i] = num.rbegin()->first;
	}
	for (int i = k - 1; i < n; i++)
	{
		printf("%d ", minv[i]);
	}
	cout << endl;
	for (int i = k - 1; i < n; i++)
	{
		printf("%d ", maxv[i]);
	}
	return 0;
}