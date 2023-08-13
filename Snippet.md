数据结构与算法模板

# 0. 要点

Eng. Ver.

```cpp
/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do something instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
```

Chs. Ver.

```cpp
/* 你应该注意的东西
 * int溢出，数组边界
 * 特殊情况(n=1?)
 * 做一些事情而不是什么也不做，保证效率
 * 把东西写在纸上
 * 不要在一个地方死磕
 */
```

# 1. VSC Snippet

## 1.1. Json 源文件

```json
{
	// Place your snippets for cpp here. Each snippet is defined under a snippet name and has a prefix, body and 
	// description. The prefix is what is used to trigger the snippet and the body will be expanded and inserted. Possible variables are:
	// $1, $2 for tab stops, $0 for the final cursor position, and ${1:label}, ${2:another} for placeholders. Placeholders with the 
	// same ids are connected.
	// Example:
	"Codeforces Multiple": {
		"prefix": "!cf",
		"body": [
			"#include <bits/stdc++.h>",
			"#define endl '\\n'",
			"// #define int long long",
			"",
			"using namespace std;",
			"",
			"void solve()",
			"{",
			"\t$0",
			"}",
			"",
			"signed main()",
			"{",
			"\tios::sync_with_stdio(false);",
			"\tcin.tie(0);",
			"\tcout.tie(0);",
			"\tint t = 1;",
			"\tcin >> t;",
			"\twhile (t--)",
			"\t\tsolve();",
			"\treturn 0;",
			"}"
		],
		"description": "Codeforces template (multiple test cases)"
	},
	"Codeforces Single": {
		"prefix": "!scf",
		"body": [
			"#include <bits/stdc++.h>",
			"#define endl '\\n'",
			"// #define int long long",
			"",
			"using namespace std;",
			"",
			"void solve()",
			"{",
			"\t$0",
			"}",
			"",
			"signed main()",
			"{",
			"\tios::sync_with_stdio(false);",
			"\tcin.tie(0);",
			"\tcout.tie(0);",
			"\tsolve();",
			"\treturn 0;",
			"}"
		],
		"description": "Codeforces template (single test case)"
	}
}
```

## 1.2. 模板本体

### 1.2.1. Codeforces 多测

```cpp
#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
```

### 1.2.2. Codeforces 单测

```cpp
#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
```

# 2. 算法

## 2.1. 埃式筛 埃拉托斯特尼筛法 Eratosthenes

时间复杂度：$O(n\log\log n)$

```cpp
const int MAXN = 1e5 + 10;
bool is_prime[MAXN]; // is_prime储存该数是否为素数

void init_prime()
{
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false; // 特判0、1不是素数
    for (int i = 2; i < MAXN; i++)     // 使用埃氏筛处理>1的情况
        if (is_prime[i])
            for (int j = 2; j * i < MAXN; j++)
                is_prime[i * j] = false;
}
```

## 2.2. 欧拉筛 线性筛 Euler

时间复杂度：$O(n)$

```cpp
// prime储存素数序列，primesize即素数数量，not_prime储存该数是否不是素数
const int MAXN = 1e5 + 10;
int prime[MAXN], primesize = 0;
bool not_prime[MAXN];

void init_prime()
{
    not_prime[0] = not_prime[1] = true; // 特判0、1不是素数
    for (int i = 2; i < MAXN; i++)      // 使用欧拉筛处理>1的情况
    {
        if (!not_prime[i])
            prime[primesize++] = i;
        for (int j = 0; j < primesize && i * prime[j] < MAXN; j++)
        {
            not_prime[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}
```

## 2.3. 二分查找 Binary Search

时间复杂度：$O(\log n)$

### 2.3.1. $\geq x$

```cpp
// a[ ]为储存数据的有序递增数组
// l ~ r为二分查找的数组范围
int l = 0, r = n - 1;
while (l < r)
{
    int mid = (l + r) / 2;
    if (a[mid] >= x)
        r = mid;
    else
        l = mid + 1;
}
```

### 2.3.2. $\leq x$

```cpp
// a[ ]为储存数据的有序递增数组
// l ~ r为二分查找的数组范围
int l = 0, r = n - 1;
while (l < r)
{
    int mid = (l + r + 1) / 2;
    if (a[mid] <= x)
        l = mid;
    else
        r = mid - 1;
}
```

### 2.3.3. 实数

```cpp
// check(int x): 判断x是否满足条件
// eps: 精度（因为浮点数误差，不可直接比大小）
// BEGIN: 查找左边界
// END: 查找右边界
bool check(int x);
double eps = 1e-6;
double l = BEGIN, r = END;
while (r - l > eps)
{
    double mid = (l + r) / 2;
    if (check(mid))
        l = mid;
    else
        r = mid;
}
```

## 2.4. 三分查找

时间复杂度：$O(\log n)$

```cpp
// f(double x): 给定区间内的凹函数或凸函数
// eps: 精度（因为浮点数误差，不可直接比大小）
// BEGIN: 查找左边界
// END: 查找右边界
double f(double x);
double eps = 1e-6;
double l = BEGIN, r = END;
while(r - l > eps)
{
    double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
    if(f(m1) > f(m2)) // 此为找最小值，若要找最大值，则改为<
        l = m1;
    else
        r = m2;
}
```

## 2.5. 深度优先搜索 DFS

```cpp
type dfs(type x, ... ) // 可以存在多个变量
{
    if( ... ) // 达成目标，找到答案
    {
        ... // 输出答案或判断最优解等等
        return;
    }
    if( ... ) // 达到搜索边界（即到边界了还没搜到，有时没有此步骤）
    {
        return;
    }
    for( ... ) // 遍历所有子节点
    {
        if( ... ) // 可以转移状态，一般用标志变量判断
        {
            ... // 修改标志变量，表明此节点不可转移
            dfs( ... ) // 搜索子节点，经常为x+1
            ... // 还原标志变量，表面此节点可转移
        }
    }
}
```

## 2.6. 广度优先搜索 BFS

```cpp
bool vis[MAXN]; // 标记是否搜索过，有时也可直接用depth来判断
int depth[MAXN]; // 储存搜索深度，有时可能为二维数组或map
queue<type> que; // STL队列，不过数组模拟队列效率更高

type bfs(type start)
{
    que.push(start); // 起点入队
    depth[start] = 0; // 起点深度0
    vis[start] = true; // 标记起点
    while (!que.empty())
    {
        type now = que.front(); // 当前节点设置为队首
        que.pop(); // 弹出队首
        if ( ... ) // 如果达到目标条件
        {
            ans = depth[now]; // 储存答案
            return; // 搜索结束
        }
        for( ... ) // 遍历now节点的所有子节点，可用数组表示方向
        {
            type next = ... // 计算出子节点
            if (!vis[next] && ... ) // 如果子节点未搜索过，且范围符合题目条件
            {
                vis[next] = true; // 标记子节点
                depth[next] = depth[now] + 1; // 子节点深度+1
                que.push(next); // 子节点入队
                // 有时题目还需输出具体路径，可用一个数组储存每个节点的上一个节点，然后在此处对数组赋值。输出时，从结尾递归反向输出即可获得具体的路径。
            }
        }
    }
}
```

## 2.7. 辗转相除法 欧几里得算法 Euclidean algorithm

时间复杂度：$O(\log(a+b))$

```cpp
int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}
```

## 2.8. 快速幂 fast power

时间复杂度：$O(\log n)$

### 2.8.1. 不取模

```cpp
ll fast_pow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b % 2 == 1)
            ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}
```

### 2.8.2. 取模

```cpp
const ll MOD = 20220128;
ll fast_pow(ll a, ll b)
{
    a %= MOD; // 开头先取一次模
    ll ans = 1;
    while (b)
    {
        if (b % 2 == 1)
            ans = ans * a % MOD; // 每次运算都取模
        a = a * a % MOD; // 每次运算都取模
        b >>= 1;
    }
    return ans;
}
```

## 2.9. KMP 算法 The Knuth-Morris-Pratt Algorithm

时间复杂度：$O(n+m)$

### 2.9.1. 计算部分匹配表

```cpp
char s1[MAXN]; // 主串
char s2[MAXN]; // 模式串
int nxt[MAXN]; // 部分匹配表
void getnext(void)
{
    nxt[0] = -1;
    int i = 0, j = -1;
    int lens2 = strlen(s2);
    while (i < lens2)
    {
        if (j == -1 || s2[i] == s2[j])
        {
            ++i;
            ++j;
            nxt[i] = j;
        }
        else
        {
            j = nxt[j];
        }
    }
}
```

### 2.9.2. KMP 本体（找所有匹配）

```cpp
char s1[MAXN]; // 主串
char s2[MAXN]; // 模式串
int nxt[MAXN]; // 部分匹配表
void kmp(void)
{
    int i = 0, j = 0;
    int lens1 = strlen(s1), lens2 = strlen(s2);
    while (i < lens1)
    {
        if (j == -1 || s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            j = nxt[j];
        }
        if (j == lens2)
        {
            printf("%d\n", i - j + 1);
        }
    }
}
```

### 2.9.3. KMP 本体（第一个匹配）

```cpp
char s1[MAXN]; // 主串
char s2[MAXN]; // 模式串
int nxt[MAXN]; // 部分匹配表
void kmp(void)
{
    int i = 0, j = 0;
    int lens1 = strlen(s1), lens2 = strlen(s2);
    while (i < lens1 && j < lens2)
    {
        if (j == -1 || s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            j = nxt[j];
        }
    }
    if (j == lens2)
    {
        printf("%d\n", i - j + 1);
    }
    else
    {
        printf("-1\n"); // -1表示没匹配到结果
    }
}
```

## 2.10. Dijkstra 算法

解决赋权图的单源最短路径问题，**不能解决负边**。

### 2.10.1. 朴素（适合稠密图）

时间复杂度：$O(|V|^2)$

```cpp
const int MAXN = 510, INF = 0x3f3f3f3f; // INF代表无穷大
int g[MAXN][MAXN]; // 邻接矩阵存图
int dist[MAXN];    // 最短距离
bool vis[MAXN];    // 访问情况
int v, e;          // v顶点数 e边数

void dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 1; i <= v; i++)
    {
        int t = -1;
        for (int j = 1; j <= v; j++)
            if (!vis[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        vis[t] = true;
        for (int j = 1; j <= v; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
}
```

### 2.10.2. 堆优化（适合稀疏图）

时间复杂度：$O((\left|E\right|+\left|V\right|)\log\left|V\right|)$ 

```cpp
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
const int MAXN = 100010, INF = 0x3f3f3f3f;           // INF代表无穷大
int E, V, S;                                         // E边数，V顶点数，S起点
vector<PII> edge[MAXN];                              // 储存连接关系，二元组为(权值,终点)
priority_queue<PII, vector<PII>, greater<PII>> pque; // 储存节点，节点距离小的在堆顶
int dist[MAXN];                                      // 储存节点距离
bool vis[MAXN];                                      // 是否已经访问过该节点的标志

void dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    pque.push({dist[1], 1});
    while (!pque.empty())
    {
        PII cur = pque.top();
        pque.pop();
        if (vis[cur.second])
            continue;
        vis[cur.second] = true;
        for (auto next : edge[cur.second])
        {
            if (dist[next.second] > dist[cur.second] + next.first)
            {
                dist[next.second] = dist[cur.second] + next.first;
                if (!vis[next.second])
                    pque.push({dist[next.second], next.second});
            }
        }
    }
}
```

## 2.11. Floyd-Warshall 算法

解决赋权图的多源最短路径问题，能解决负边，不能解决负环。

时间复杂度：$O(\left|V\right|^3)$

```cpp
const int MAXN = 1010, INF = 0x3f3f3f3f;
int e, v;             // e边数 v顶点数
int dist[MAXN][MAXN]; // dist[x][y]代表x到y的距离

void floyd_init(void)
{
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 1; i <= v; i++)
        dist[i][i] = 0;
}

void floyd(void)
{
    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
```

## 2.12. 最短路径快速算法 SPFA

平均时间复杂度：$O(\left|E\right|)$

最差时间复杂度：$O(\left|V\right|\cdot\left|E\right|)$

### 2.12.1. 最短路

```cpp
const int MAXN = 1e5 + 10, INF = 0x3f3f3f3f; // INF代表无穷大
int e, v, s;                                 // e边数 v顶点数 s起点
vector<pair<int, int>> edge[MAXN];           // 邻接表存图 pair为(距离, 终点)
queue<int> que;                              // STL队列
int dist[MAXN];                              // 最短距离
bool vis[MAXN];                              // 是否入队

void spfa(int src)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[src] = 0;
    que.push(src);
    vis[src] = true;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        vis[cur] = false;
        for (auto next : edge[cur])
        {
            if (dist[next.second] > dist[cur] + next.first)
            {
                dist[next.second] = dist[cur] + next.first;
                if (!vis[next.second])
                {
                    que.push(next.second);
                    vis[next.second] = true;
                }
            }
        }
    }
}
```

### 2.12.2. 判负权回路

```cpp
const int MAXN = 1e5 + 10, INF = 0x3f3f3f3f;
int E, V, S;
vector<pair<int, int>> edge[MAXN];
queue<int> que;
int dist[MAXN], cnt[MAXN];
bool vis[MAXN];

bool spfa()
{
    for (int i = 1; i <= V; i++)
    {
        que.push(i);
        vis[i] = true;
    }
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        vis[cur] = false;
        for (auto next : edge[cur])
        {
            if (dist[next.second] > dist[cur] + next.first)
            {
                dist[next.second] = dist[cur] + next.first;
                cnt[next.second] = cnt[cur] + 1;
                if (cnt[next.second] >= V)
                    return true;
                if (!vis[next.second])
                {
                    que.push(next.second);
                    vis[next.second] = true;
                }
            }
        }
    }
    return false;
}
```

## 2.13. 克鲁斯卡尔算法 Kruskal

时间复杂度：$O(\left|E\right|\log\left|V\right|)$

适合稀疏图

```cpp
const int MAXN = 1e5 + 10, INF = 0x3f3f3f3f;
int v, e;     // v顶点数 e边数
int fa[MAXN]; // 并查集
struct Edge   // 边的结构体，重载了<供sort()
{
    int start, end, dist;
    bool operator<(const Edge &x) const
    {
        return dist < x.dist;
    }
};
vector<Edge> edges; // 邻接表存边

inline void init(int n)
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

inline void merge(int i, int j)
{
    fa[find(i)] = find(j);
}

int kruskal()
{
    sort(edges.begin(), edges.end());
    int ans = 0, selected = 0;
    bool flag = false;
    for (auto ed : edges)
    {
        if (find(ed.start) != find(ed.end))
        {
            merge(ed.start, ed.end);
            ans += ed.dist;
            if (++selected == v - 1)
            {
                flag = true;
                break;
            }
        }
    }
    return flag ? ans : INF;
}
```

## 2.14. 普林姆算法 Prim

### 2.14.1. 朴素（适合稠密图）

时间复杂度：$O(\left|V\right|^2)$

```cpp
const int MAXN = 510, INF = 0x3f3f3f3f; // INF代表无穷大
int g[MAXN][MAXN]; // 邻接矩阵存图
int dist[MAXN];    // 距离已选择点的最短距离
int vis[MAXN];     // 点是否选择
int v, e;          // v顶点数 e边数

int prim()
{
    int ans = 0;
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 0; i < v; i++)
    {
        int t = -1;
        for (int j = 1; j <= v; j++)
            if (!vis[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        if (dist[t] == INF)
            return INF;
        ans += dist[t];
        vis[t] = true;
        for (int j = 1; j <= v; j++)
            dist[j] = min(dist[j], g[t][j]);
    }
    return ans;
}
```

### 2.14.2. 堆优化

时间复杂度：$O((\left|E\right|+\left|V\right|)\log\left|V\right|)$

```cpp
typedef pair<int, int> PII;
const int MAXN = 100010, INF = 0x3f3f3f3f;           // INF代表无穷大
int E, V;                                            // E边数 V顶点数
vector<PII> edge[MAXN];                              // 储存边，二元组为(权值,终点)
priority_queue<PII, vector<PII>, greater<PII>> pque; // 短的边在堆顶
int dist[MAXN];                                      // 储存节点到已选择点的最短距离
bool vis[MAXN];                                      // 是否已选择该点

int prim()
{
    int ans = 0, cnt = 0;
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    pque.push({dist[1], 1});
    while (!pque.empty())
    {
        PII cur = pque.top();
        pque.pop();
        if (vis[cur.second])
            continue;
        ans += cur.first;
        cnt++;
        vis[cur.second] = true;
        for (auto next : edge[cur.second])
        {
            if (dist[next.second] > next.first)
            {
                dist[next.second] = next.first;
                if (!vis[next.second])
                    pque.push({dist[next.second], next.second});
            }
        }
    }
    return cnt == V ? ans : INF;
}
```

## 2.15. 排序算法

| 排序算法                  | 最好情况  | 平均情况  | 最坏情况  | 空间占用 | 稳定性     |
| ------------------------- | --------- | --------- | --------- | -------- | ---------- |
| 冒泡排序 (Bubble sort)    | $n$       | $n^2$     | $n^2$     | $1$      | $\text{Y}$ |
| 选择排序 (Selection sort) | $n^2$     | $n^2$     | $n^2$     | $1$      | $\text{N}$ |
| 插入排序 (Insertion sort) | $n$       | $n^2$     | $n^2$     | $1$      | $\text{Y}$ |
| 希尔排序 (Shellsort)      | $n\log n$ | $n^{4/3}$ | $n^{3/2}$ | $1$      | $\text{N}$ |
| 归并排序 (Merge sort)     | $n\log n$ | $n\log n$ | $n\log n$ | $n$      | $\text{Y}$ |
| 快速排序 (Quicksort)      | $n\log n$ | $n\log n$ | $n^2$     | $\log n$ | $\text{N}$ |
| 堆排序 (Heapsort)         | $n\log n$ | $n\log n$ | $n\log n$ | $1$      | $\text{N}$ |
| 计数排序 (Counting sort)  | $-$       | $n+r$     | $n+r$     | $n+r$    | $\text{Y}$ |
| 桶排序 (Bucket sort)      | $-$       | $n+r$     | $n+r$     | $n+r$    | $\text{Y}$ |

### 2.15.1. 冒泡

```cpp
void bubble_sort(int arr[], int l, int r)
{
    for (int i = r; i >= l + 1; i--)
    {
        bool swapped = false;
        for (int j = l + 1; j <= i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                swapped = true;
            }
        }
        if (!swapped)
            return;
    }
}
```

### 2.15.2. 选择

```cpp
void selection_sort(int arr[], int l, int r)
{
    for (int i = l; i <= r - 1; i++)
    {
        int j_min = i;
        for (int j = i + 1; j <= r; j++)
        {
            if (arr[j] < arr[j_min])
                j_min = j;
        }
        if (j_min != i)
            swap(arr[i], arr[j_min]);
    }
}
```

### 2.15.3. 插入

```cpp
void insertion_sort(int arr[], int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        int num = arr[i];
        int j = i - 1;
        while (j >= l && num < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = num;
    }
}
```

### 2.15.4. 归并

```cpp
const int MAXN = 100;
int tmp[MAXN];
void merge_sort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }
    while (i <= mid)
        tmp[k++] = arr[i++];
    while (j <= r)
        tmp[k++] = arr[j++];
    for (int m = l, n = 0; m <= r; m++, n++)
        arr[m] = tmp[n];
}
```

### 2.15.5. 快速

```cpp
void quicksort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int x = arr[(l + r) / 2], i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            i++;
        while (arr[i] < x);
        do
            j--;
        while (arr[j] > x);
        if (i < j)
            swap(arr[i], arr[j]);
    }
    quicksort(arr, l, j);
    quicksort(arr, j + 1, r);
}
```

## 2.16. 二分图

### 2.16.1. 染色法判二分图

时间复杂度：$O(\left|V\right|+\left|E\right|)$

```cpp
const int SIZE = 1e5 + 10;
int V, E;                   // V为顶点，E为边
vector<int> edge[SIZE];     // vector邻接表，可改为数组邻接表效率更高
int color[SIZE];            // 储存颜色，用0和1表示两种颜色，-1表示还未染色。重要：使用前先memset为-1
/* vector<int> ans[2]; */   // 储存两颜色的顶点，某些题目需要输出

bool dfs(int n, int c)
{
    color[n] = c;
    /* ans[colr].push_back(node); */   // 储存两颜色的顶点，某些题目需要输出
    for (auto nxt : edge[n])
    {
        if (color[n] == -1)
        {
            if (!dfs(nxt, !c))
                return false;
        }
        else if (color[nxt] == c)
        {
            return false;
        }
    }
    return true;
}
```

非联通：

```cpp
bool flag = true;
for (int i = 1; i <= V; i++)
{
    if (color[i] == -1)
    {
        if (!dfs(i, 0))
        {
            flag = false;
            break;
        }
    }
}
```

### 2.16.2. 最大匹配 匈牙利算法  Hungarian Algorithm

时间复杂度：$O(\left|V\right|\cdot \left|E\right|)$

```cpp
#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1010;

int n1, n2, m;          // n1为二分图的一个子图的顶点数，n2为另一个子图的顶点数，m为边数。
vector<int> edge[SIZE]; // 这里使用vector存图
int match[SIZE];        // 储存n2中的某个顶点匹配的n1中的顶点
bool vis[SIZE];         // 标记n2中的某个顶点是否已经匹配过

bool find(int x)
{
    // 遍历所有与x连接的n2内的顶点i
    for (auto i : edge[x])
    {
        // 如果顶点i本轮还未匹配过
        if (!vis[i])
        {
            // 将其标记
            vis[i] = true;
            // 若顶点i还没有匹配到任何n1中顶点，则直接把i与x匹配
            // 如果i已经匹配上，则查询与i匹配的n1中的元素能否换一个匹配，若可以，则将i与x匹配
            if (match[i] == 0 || find(match[i]))
            {
                match[i] = x;
                return true;
            }
        }
    }
    // 如果没法匹配上，返回false
    return false;
}

int main(void)
{
    cin >> n1 >> n2 >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // 只用得到从n1到n2的边，因此只存了单向边
        edge[u].push_back(v);
    }
    int cnt = 0; // 匹配的数量
    // 从n1第一个元素开始，尝试匹配到最后一个元素
    for (int i = 1; i <= n1; i++)
    {
        // 先清空所有n2的访问情况
        memset(vis, false, sizeof(vis));
        // 如果匹配上则匹配数+1
        if (find(i))
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
```

## 2.17. 背包模型

### 2.17.1. 0/1 背包

时间复杂度：$O(N\cdot V)$

空间复杂度：$O(N\cdot V)$

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 1010;
int N, V;             // N-物品数量 V-背包容积
int v[SIZE], w[SIZE]; // v-体积 w-价值
int dp[SIZE][SIZE];   // 二维动态规划

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << dp[N][V] << endl;
    return 0;
}
```

时间复杂度：$O(N\cdot V)$

空间复杂度：$O(V)$

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 1010;
int N, V;             // N-物品数量 V-背包容积
int v[SIZE], w[SIZE]; // v-体积 w-价值
int dp[SIZE];         // 一维动态规划

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= N; i++)
        for (int j = V; j >= v[i]; j--)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    cout << dp[V] << endl;
    return 0;
}
```

### 2.17.2. 完全背包

时间复杂度：$O(N\cdot V^2)$ (最坏情况)

空间复杂度：$O(N\cdot V)$

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 1010;
int N, V;
int v[SIZE], w[SIZE];
int dp[SIZE][SIZE];

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= V; j++)
            for (int k = 0; k * v[i] <= j; k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
    cout << dp[N][V] << endl;
    return 0;
}
```

时间复杂度：$O(N\cdot V)$

空间复杂度：$O(N\cdot V)$

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 1010;
int N, V;
int v[SIZE], w[SIZE];
int dp[SIZE][SIZE];

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i])
                dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
        }
    }
    cout << dp[N][V] << endl;
    return 0;
}
```

时间复杂度：$O(N\cdot V)$

空间复杂度：$O(V)$

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 1010;
int N, V;
int v[SIZE], w[SIZE];
int dp[SIZE];

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= N; i++)
        for (int j = v[i]; j <= V; j++)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    cout << dp[V] << endl;
    return 0;
}
```

### 2.17.3. 多重背包

时间复杂度：$O(N\cdot V^2)$ (最坏情况)

空间复杂度：$O(V)$

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 1010;
int N, V;
int v[SIZE], w[SIZE], s[SIZE];
int dp[SIZE];

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
        cin >> v[i] >> w[i] >> s[i];
    for (int i = 1; i <= N; i++)
        for (int j = V; j >= v[i]; j--)
            for (int k = 0; k * v[i] <= j && k <= s[i]; k++)
                dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
    cout << dp[V] << endl;
    return 0;
}
```

时间复杂度：$O(N\cdot\log{S}\cdot V)$

空间复杂度：$O(V)$ (已包含空间优化)

```cpp 
#include <iostream>
#include <algorithm>

using namespace std;

// 需要注意各个数组的大小
const int SIZE_NlogS = 25000, SIZE_V = 2010;
int N, V, idx;
int v[SIZE_NlogS], w[SIZE_NlogS];
int dp[SIZE_V];

int main()
{
    cin >> N >> V;
    // 物品读入
    for (int i = 1; i <= N; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;
        // 物品打包
        while (k <= s)
        {
            v[++idx] = a * k;
            w[idx] = b * k;
            s -= k;
            k *= 2;
        }
        if (s)
        {
            v[++idx] = a * s;
            w[idx] = b * s;
        }
    }
    // 01-背包问题
    for (int i = 1; i <= idx; i++)
        for (int j = V; j >= v[i]; j--)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    cout << dp[V] << endl;
    return 0;
}
```

时间复杂度：$O(N\cdot V)$

空间复杂度：$O(V)$ (已包含空间优化) 

```cpp
#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    int N, V;
    cin >> N >> V;
    vector<int> v(N + 10), w(N + 10), s(N + 10);
    for (int i = 1; i <= N; i++)
        cin >> v[i] >> w[i] >> s[i];
    vector<int> dp(V + 10), lst(V + 10), que(V + 10);
    for (int i = 1; i <= N; i++)
    {
        lst = dp;
        for (int r = 0; r < v[i]; r++)
        {
            int hh = 0, tt = -1;
            for (int k = r; k <= V; k += v[i])
            {
                if (hh <= tt && que[hh] < k - s[i] * v[i])
                    ++hh;
                while (hh <= tt && lst[que[tt]] - (que[tt] - r) / v[i] * w[i] <= lst[k] - (k - r) / v[i] * w[i])
                    --tt;
                if (hh <= tt)
                    dp[k] = max(dp[k], lst[que[hh]] - (que[hh] - k) / v[i] * w[i]);
                que[++tt] = k;
            }
        }
    }
    cout << dp[V] << endl;
    return 0;
}
```

### 2.17.4. 分组背包

时间复杂度：$O(V\cdot\sum{S})$

空间复杂度：$O(V)$ (已包含空间优化) 

```cpp
#include <bits/stdc++.h>

using namespace std;

const int SIZE = 110;
int N, V;
int v[SIZE][SIZE], w[SIZE][SIZE], S[SIZE];
int dp[SIZE];

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
    {
        cin >> S[i];
        for (int j = 0; j < S[i]; j++)
            cin >> v[i][j] >> w[i][j];
    }
    for (int i = 0; i <= N; i++)
        for (int j = V; j >= 0; j--)
            for (int k = 0; k < S[i]; k++)
                if (v[i][k] <= j)
                    dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);
    cout << dp[V] << endl;
    return 0;
}
```

### 2.17.5. 混合背包

```cpp
#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N, V;
    cin >> N >> V;
    vector<int> dp(V + 10);
    for (int i = 1; i <= N; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        if (s == 0) // 完全背包
        {
            for (int j = v; j <= V; j++)
                dp[j] = max(dp[j], dp[j - v] + w);
        }
        else // 0-1背包 和 多重背包
        {
            s = abs(s); // 一律当多重背包转化成0-1背包
            vector<int> vv, ww;
            int k = 1;
            while (k <= s)
            {
                vv.push_back(v * k);
                ww.push_back(w * k);
                s -= k;
                k *= 2;
            }
            if (s)
            {
                vv.push_back(v * s);
                ww.push_back(w * s);
            }
            for (int j = 0; j < vv.size(); j++)
                for (int k = V; k >= vv[j]; k--)
                    dp[k] = max(dp[k], dp[k - vv[j]] + ww[j]);
        }
    }
    cout << dp[V] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
```

## 2.18. 高精度

### 2.18.1. I/O

```cpp
/* 变量 */
string a;
vector<int> A;

/* 输入 */
cin >> a; // 首先以字符串形式读入
for (int i = a.size() - 1; i >= 0; i--)
    A.push_back(a[i] - '0'); // 反向将字符串每位写入整型数组，注意减去偏移量‘0’

/* 输出 */
for (int i = A.size() - 1; i >= 0; i--)
    cout << A[i]; // 反向输出整型数组每一位
```

### 2.18.2. BI + BI

```cpp
vector<int> add(vector<int> &A, vector<int> &B)
{
    if (B.size() > A.size())
        return add(B, A);
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t = t > 9 ? 1 : 0;
    }
    if (t)
        C.push_back(1);
    return C;
}
```

### 2.18.3. BI - BI

```cpp
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if (i < B.size())
            t -= B[i];
        C.push_back((t + 10) % 10);
        t = t < 0 ? 1 : 0;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}
```

```cpp
bool cmp(vector<int> &A, vector<int> &B) // 若A>=B返回true，否则返回false
{
    if (A.size() != B.size())
        return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--)
        if (A[i] != B[i])
            return A[i] > B[i];
    return true;
}

int main()
{
    if (cmp(A, B))
        vector<int> C = sub(A, B);
    else
        vector<int> C = sub(B, A); // 这种情况输出时记得先输出一个‘-’符号
}
```

### 2.18.4. BI * I

```cpp
vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size())
            t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}
```

### 2.18.5. BI / I

```cpp
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}
```

## 2.19. 贝尔曼-福特算法 Bellman-Ford

解决赋权图的单源最短路径问题，能解决负边，能解决负环。

时间复杂度：$O(\left|V\right|\cdot\left|E\right|)$

```cpp
const int MAXN = 510, MAXM = 1e4 + 10, INF = 0x3f3f3f3f;
int v, e, k;                  // v顶点数 e边数 k经过边数限制
int dist[MAXN], backup[MAXN]; // dist最短距离 backup备份上一次迭代
struct Edge
{
    int a, b, w;              // a起点 b终点 w权值  
} edges[MAXM];                // 结构图数组存边

int bellman_ford()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 0; i < k; i++)
    {
        memcpy(backup, dist, sizeof(dist));
        for (int j = 0; j < e; j++)
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    return dist[v] > INF / 2 ? INF : dist[v];
}
```

## 2.20. 矩阵加速算法

### 2.20.1. $n$ 阶方阵乘法

```cpp
vector<vector<ll>> mat_mul(vector<vector<ll>> a, vector<vector<ll>> b, ll mod)
{
    int n = a.size();
    vector<vector<ll>> res(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                res[i][j] = (res[i][j] + a[i][k] * b[k][j] % mod) % mod;
    return res;
}
```

### 2.20.2. 矩阵快速幂

```cpp
vector<vector<ll>> mat_pow(vector<vector<ll>> a, ll b, ll mod)
{
    int n = a.size();
    vector<vector<ll>> res(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    while (b)
    {
        if (b % 2)
            res = mat_mul(res, a, mod);
        a = mat_mul(a, a, mod);
        b /= 2;
    }
    return res;
}
```

## 2.21. 最长上升子序列 Longest Increasing Subsequence

### 2.21.1. 动态规划

时间复杂度：$O(n^2)$ 

```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int N, a[MAXN];
int dp[MAXN];

int main()
{
    a[0] = INT32_MIN;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
```

### 2.21.2. 贪心、二分、单调栈

时间复杂度：$O(n\log n)$

```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int N, a[MAXN];
vector<int> v;

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    v.push_back(a[1]);
    for (int i = 2; i <= N; i++)
    {
        if (a[i] > v.back())
            v.push_back(a[i]);
        else
            v[lower_bound(v.begin(), v.end(), a[i]) - v.begin()] = a[i];
    }
    cout << v.size() << endl;
    return 0;
}
```

## 2.22. 最长公共上升子序列 Longest Common Increasing Subsequence

### 2.22.1. 三重循环 DP

时间复杂度：$O(n^3)$

```cpp
void solve()
{
    int N;
    cin >> N;
    vector<int> A(N + 10), B(N + 10);
    vector<vector<int>> dp(N + 10, vector<int>(N + 10, 0));
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (A[i] == B[j])
                for (int k = 0; k < j; k++)
                    if (B[k] < B[j])
                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans = max(dp[N][i], ans);
    cout << ans << endl;
}
```

### 2.22.2. 将 DP 进行简化

时间复杂度：$O(n^2)$

```cpp
void solve()
{
    int N;
    cin >> N;
    vector<int> A(N + 10), B(N + 10);
    vector<vector<int>> dp(N + 10, vector<int>(N + 10, 0));
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];
    for (int i = 1; i <= N; i++)
    {
        int maxv = 1;
        for (int j = 1; j <= N; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (A[i] == B[j])
                dp[i][j] = max(dp[i][j], maxv);
            if (B[j] < A[i])
                maxv = max(maxv, dp[i - 1][j] + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans = max(dp[N][i], ans);
    cout << ans << endl;
}
```

## 2.23. 最近公共祖先 Lowest Common Ancestor

### 2.23.1. 倍增法

预处理：$O(V\log d)$，其中 $d$ 为树的深度。

计算：$O(\log d)$，其中 $d$ 为树的深度。

```cpp
constexpr int MAXN = 1e6 + 10;
int h[MAXN], e[MAXN], ne[MAXN], idx;
int mylog2[MAXN]; // \lfloor log_{2}{x} \rfloor + 1
int fa[MAXN][30], dep[MAXN];

void init()
{
    memset(h, -1, sizeof(h));
    for (int i = 1; i < MAXN; i++)
        mylog2[i] = mylog2[i - 1] + (1 << mylog2[i - 1] == i);
}

void dfs(int now, int father)
{
    fa[now][0] = father;
    dep[now] = dep[father] + 1;
    for (int i = 0; i < mylog2[dep[now]]; i++)
        fa[now][i + 1] = fa[fa[now][i]][i];
    for (int i = h[now]; i != -1; i = ne[i])
        if (e[i] != father)
            dfs(e[i], now);
}

int lca(int a, int b)
{
    if (dep[a] < dep[b])
        swap(a, b); // make a >= b
    while (dep[a] > dep[b])
        a = fa[a][mylog2[dep[a] - dep[b]] - 1];
    if (a == b)
        return a;
    for (int i = mylog2[dep[a]] - 1; i >= 0; i--)
    {
        if (fa[a][i] != fa[b][i])
        {
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    return fa[a][0];
}
```

### 2.23.2. 树链剖分

预处理：$O(n)$

计算：$O(\log n)$

```cpp
int lca(int u, int v) 
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] > dep[top[v]])
            u = fa[top[u]];
        else
            v = fa[top[v]];
    }
    return dep[u] > dep[v] ? v : u;
}
```

## 2.24. 树链剖分（重链剖分）

链式前向星存图，下标从 $1$ 开始。

### 2.24.1. 剖分

```cpp
void dfs1(int now)
{
    son[now] = -1;
    siz[now] = 1;
    for (int i = h[now]; i; i = ne[i])
    {
        int &nxt = e[i];
        if (nxt == fa[now])
            continue;
        fa[nxt] = now;
        dep[nxt] = dep[now] + 1;
        /* 如果是边权
        val[nxt] = w[i];
        */
        dfs1(nxt);
        siz[now] += siz[nxt];
        if (son[now] == -1 || siz[son[now]] < siz[nxt])
            son[now] = nxt;
    }
}
```

```cpp
void dfs2(int now, int tp)
{
    top[now] = tp;
    dfn[now] = ++cnt;
    rnk[cnt] = now;
    if (son[now] == -1)
        return;
    dfs2(son[now], tp);
    for (int i = h[now]; i; i = ne[i])
    {
        int &nxt = e[i];
        if (nxt == son[now] || nxt == fa[now])
            continue;
        dfs2(nxt, nxt);
    }
}
```

### 2.24.2. 操作

```cpp
int do_something(int a, int b)
{
    while (top[a] != top[b])
    {
        int ta = top[a], tb = top[b];
        if (dep[ta] >= dep[tb])
        {
            // do something in range [dfn[ta], dfn[a]]
            a = fa[ta];
        }
        else
        {
            // do something in range [dfn[tb], dfn[b]]
            b = fa[tb];
        }
    }
    if (dep[a] > dep[b])
        swap(a, b);
    // do something in range [dfn[a], dfn[b]]     如果是点权
    // do something in range [dfn[a] + 1, dfn[b]] 如果是边权
    return ans;
}
```

# 3. 数据结构

## 3.1. 单调队列 Monotonic Queue

时间复杂度：$O(n)$

### 3.1.1. STL 队列

```cpp
// val[ ]: 储存数据的数组
// n: 需要计算的范围
// k: 给定的区间大小
// q: STL双向队列，储存val[ ]中元素的数组序号
deque<int> q;
for (int i = 0; i < n; i++)
{
    // 去尾操作
    while (!q.empty() && val[q.back()] > val[i])
        q.pop_back();
    // 新元素（的序号）入队
    q.push_back(i);
    // 判断是否需要进行下面两个操作
    if (i >= k - 1)
    {
        // 删头操作
        if (q.front() < i - k + 1)
            q.pop_front();
        // 输出操作
        cout << val[q.front()] << ' ';
    }
}
```

### 3.1.2. 数组队列

```cpp
// val[ ]: 储存数据的数组
// n: 需要计算的范围
// k: 给定的区间大小
// q: 数组队列，储存val[ ]中元素的数组序号
// h, t: 队头、队尾指针，(0, -1)为空
int q[MAXN], h = 0, t = -1;
for (int i = 0; i < n; i++)
{
    while (h <= t && val[q[t]] > val[i])
        t--;
    q[++t] = i;
    if (i >= k - 1)
    {
        if (q[h] < i - k + 1)
            h++;
        cout << val[q[h]] << ' ';
    }
}
```

## 3.2. 并查集 Disjoint Set Union

### 3.2.1. 朴素

```cpp
// 朴素版并查集（不推荐使用）
int fa[MAXN];
inline void init(int n)
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int find(int x)
{
    if(fa[x] == x)
        return x;
    else
        return find(fa[x]);
}

inline void merge(int i, int j)
{
    fa[find(i)] = find(j);
}
```

### 3.2.2. 路径压缩

```cpp
// 路径压缩版并查集（最常使用）
int fa[MAXN];
inline void init(int n)
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x])); // 注1
}

inline void merge(int i, int j)
{
    fa[find(i)] = find(j);
}
```

### 3.2.3. 路径压缩、按秩合并

```cpp
int fa[MAXN], rnk[MAXN];
inline void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        rnk[i] = 1;
    }
}

int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

void merge(int i, int j)
{
    int x = find(i), y = find(j);
    if (rnk[x] <= rnk[y])
        fa[x] = y;
    else
        fa[y] = x;
    if (rnk[x] == rnk[y] && x != y)
        rnk[y]++;
}
```

### 3.2.4. 维护集合数量

```cpp
int fa[MAXN], sz[MAXN];
inline void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        sz[i] = 1; // 全部初始化为1
    }
}

int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

inline int size(int x) // 查询一个集合的元素数量
{
    return sz[find(x)];
}

inline void merge(int x, int y)
{
    if (find(x) == find(y)) // 如果x,y在同一集合则跳过
        return;
    sz[find(y)] += sz[find(x)]; // 将待合并集合的元素数量加到目标集合的元素数量上
    fa[find(x)] = find(y);
}
```

### 3.2.5. 到根节点的距离

```cpp
int fa[MAXN], ds[MAXN];
inline void init(int n)
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int find(int n)
{
    if (fa[n] == n)
        return n;
    int res = find(fa[n]); // 先路径压缩
    ds[n] += ds[fa[n]];    // 再更新距离
    return fa[n] = res;    // 再路径压缩
}

void merge(int a, int b, int r) // r为两节点的距离关系
{
    int faa = find(a), fab = find(b); // 一定要先储存好父节点，否则下面更新后会变化。
    fa[faa] = fab;
    ds[faa] = ds[b] - ds[a] + r;
}
```

## 3.3. 链式前向星

### 3.3.1. 数组，下标从 0

h 初始化为 -1

```cpp
constexpr int MAXN = 1e5 + 10;
int h[MAXN], e[MAXN], ne[MAXN], idx;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

for (int i = h[x]; ~i; i = ne[i])
{
    int &cur = e[i];
    // do something...
}
```

### 3.3.2. 数组，下标从 1

h 初始化为 0

```cpp
constexpr int MAXN = 1e5 + 10;
int h[MAXN], e[MAXN], ne[MAXN], idx;

void add(int a, int b)
{
    idx++;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

for (int i = h[x]; i; i = ne[i])
{
    int &cur = e[i];
    // do something...
}
```

### 3.3.3. 结构体

```cpp
struct EDGE
{
    int to, weight, next;
} edge[SIZE];
int head[SIZE];

int V, E; // E边数，V顶点数
int cnt;  // 储存边时的下标

void init()
{
    cnt = 0;
    // 全部初始化为-1
    for (int i = 1; i <= V; i++)
        head[i] = -1;
};

void add_edge(int start, int end, int weight)
{
    edge[cnt].to = end;           // 终点
    edge[cnt].weight = weight;    // 长度
    edge[cnt].next = head[start]; // 下一条边
    head[start] = cnt++;
}

for (int i = head[x]; i != -1; i = edge[j].next)
{
    // do something...
}
```

## 3.4. 树状数组 Fenwick Tree

时间复杂度：$O(\log n)$

```cpp
const int MAXN = 1e6;
int Fenwick_Tree[MAXN];
// 如果不是全局变量记得初始化为0

// 查询(0,pos]的区间和
int query(int pos)
{
    int ans = 0;
    for (int i = pos; i; i -= i & -i)
        ans += Fenwick_Tree[i];
    return ans;
}

// 查询[l,r]的区间和
inline int query(int l, int r)
{
    return query(r) - query(l - 1);
}

// 第pos位加上val
void update(int pos, int val)
{
    for (int i = pos; i < MAXN; i += i & -i)
        Fenwick_Tree[i] += val;
}
```

## 3.5. 字典树 Trie

时间复杂度：$O(m)$. $m$ 为待操作字符串的长度

```cpp
const int MAXN = 1e6 + 10;
int son[MAXN][26], cnt[MAXN], idx;

void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int c = str[i] - 'a';
        if (!son[p][c])
            son[p][c] = ++idx;
        p = son[p][c];
    }
    cnt[p]++;
}

int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int c = str[i] - 'a';
        if (!son[p][c])
            return 0;
        p = son[p][c];
    }
    return cnt[p];
}
```

## 3.6. 堆 Heap

### 3.6.1. 上下滤

```cpp
const int MAXN = 1e6 + 10; // 堆的最大大小
int heap[MAXN];            // 储存堆的数组
int idx;                   // 堆的当前大小

void up(int u)
{
    while (u / 2 && heap[u] < heap[u / 2])
    {
        swap(heap[u], heap[u / 2]);
        u /= 2;
    }
}

void down(int u)
{
    int t = u;
    if (u * 2 <= idx && heap[u * 2] < heap[t])
        t = u * 2;
    if (u * 2 + 1 <= idx && heap[u * 2 + 1] < heap[t])
        t = u * 2 + 1;
    if (t != u)
    {
        swap(heap[t], heap[u]);
        down(t);
    }
}
```

### 3.6.2. 建堆

```cpp
for (int i = n / 2; i > 0; i--)
    down(i);
```

### 3.6.3. 取得堆中最小值

堆顶即为最小值。

### 3.6.4. 插入

```cpp
// num 为待插入的数
heap[++idx] = num;
up(idx);
```

### 3.6.5. 删除

```cpp
// id 为待删除节点的编号
heap[id] = heap[idx--];
up(id);
down(id);
```

### 3.6.6. 修改

```cpp
// id 为待修改节点的编号，num 为新数值
heap[id] = num;
up(id);
down(id);
```

### 3.6.7. 带映射关系的堆

```cpp
// 注意该函数的形参 a, b 是下标，和内置的 swap 函数不同。
inline void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(heap[a], heap[b]);
}

inline void insert(int num)
{
    idx++; 
    id++;
    heap[idx] = num;
    ph[id] = idx;    // 建立插入序号->节点编号的映射
    hp[idx] = id;    // 建立节点编号->插入序号的映射
    up(idx);
}

inline int getmin()
{
    return heap[1];
}

inline void erase()
{
    heap_swap(1, idx); // 用heap_swap而不是直接赋值，才能维护映射关系
    idx--;
    down(1);
}

inline void erase(int id)
{
    int k = ph[id];    // 需要先储存k，防止操作过程中变化
    heap_swap(k, idx); // 用heap_swap而不是直接赋值，才能维护映射关系
    idx--;
    up(k);
    down(k);
}

inline void modify(int id, int num)
{
    int k = ph[id]; // 需要先储存k，防止操作过程中变化
    heap[k] = num;
    up(k);
    down(k);
}
```

## 3.7. 哈希表 Hash Table

### 3.7.1. 开放寻址法 Open Addressing

```cpp
// 开放寻址法
const int SIZE = 200003, NONE = 0x3f3f3f3f;
// SIZE为取模的数，同时也是数组大小，NONE为定义的代表空位的数字，需要不在哈希函数值域内
int hs[SIZE];
// hs哈希表 !!!hs每一字节需初始化为0x3f!!!

inline int f(int x) // 哈希函数
{
    return (x % SIZE + SIZE) % SIZE;
}

int find(int x) // 若x在表内，返回x的位置；若x不在表内，返回x应当插入的位置
{
    int y = f(x);
    while (hs[y] != NONE && hs[y] != x) // 当找到空位或找到了x就停下来
    {
        // 找不到就一直找下一位，找到最后一位再从第0位开始找
        y++;
        if (y == SIZE)
            y = 0;
    }
    return y;
}

void insert(int x) // 将x插入表内
{
    int k = find(x);
    hs[k] = x;
}

bool query(int x) // 查询x是否在表内
{
    int k = find(x);
    return hs[k] == x;
}
```

### 3.7.2. 单独链表法 Separate Chaining

```cpp
/* 单独链表法 使用数组模拟链表实现 */

const int SIZE = 100003;
// SIZE为取模的数，同时也是数组大小
int hs[SIZE], val[SIZE], nxt[SIZE], idx;
// hs哈希表储存链表头指针，val链表节点数据域，nxt链表节点指针域，idx链表长度
// !!!hs每一字节需初始化为-1!!!

inline int f(int x) // 哈希函数
{
    return (x % SIZE + SIZE) % SIZE;
}

void insert(int x) // 将x插入表内
{
    int y = f(x);
    // 下面的操作为链表头插法
    val[idx] = x;
    nxt[idx] = hs[y];
    hs[y] = idx++;
}

bool query(int x) // 查询x是否在表内
{
    int y = f(x);
    for (int i = hs[y]; i != -1; i = nxt[i]) // 遍历链表
        if (val[i] == x)
            return true;
    return false;
}
```

## 3.8. ST 表 Sparse Table

在 $O(n\log n)$ 完成初始化，在 $O(1)$ 回答每个区间查询。不支持修改数据。

```cpp
void init()
{
    for (int i = 1; i <= N; i++)
        cin >> f[0][i];
    for (int i = 1; i <= LOGN; i++)
        for (int j = 1; j <= N - (1 << i) + 1; j++)
            f[i][j] = max(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
}

int query(int l, int r)
{
    int len = r - l + 1;
    int pow = 0, pow2 = 1;
    while (pow2 * 2 <= len)
    {
        pow++;
        pow2 *= 2;
    }
    return max(f[pow][l], f[pow][r - pow2 + 1]);
}
```

## 3.9 线段树 Segment Tree

### 3.9.1. 维护区间和，包含 + 运算

```cpp
// s, t  - 建树的区间起点和终点
// p     - 当前的节点编号
// sum[] - 线段树维护区间和
// a[]   - 原数组 (1 ~ n)
// 如果要对长度为 n 的数列建立线段树，则调用 build(1, n, 1);
void build(int s, int t, int p)
{
    if (s == t)
    {
        sum[p] = a[s];
        return;
    }
    int m = s + (t - s) / 2;
    build(s, m, p * 2);
    build(m + 1, t, p * 2 + 1);
    sum[p] = sum[p * 2] + sum[p * 2 + 1];
}

// l, r      - 要更新的区间的起点和终点
// c         - 更新值 +c
// s, t      - 当前正在考察的区间的起点和终点
// p         - 当前的节点编号
// sum[]     - 线段树维护区间和
// add_val[] - 加法修改标记
// 如果要对长度为 n 的数列的 [a, b] 区间 +c，则调用 add(a, b, c, 1, n, 1);
void add(int l, int r, int c, int s, int t, int p)
{
    if (l <= s && t <= r)
    {
        sum[p] += (t - s + 1) * c;
        add_val[p] += c;
        return;
    }
    int m = s + (t - s) / 2;
    if (add_val[p] && s != t)
    {
        sum[p * 2] += add_val[p] * (m - s + 1);
        sum[p * 2 + 1] += add_val[p] * (t - m);
        add_val[p * 2] += add_val[p];
        add_val[p * 2 + 1] += add_val[p];
        add_val[p] = 0;
    }
    if (l <= m)
        add(l, r, c, s, m, p * 2);
    if (r > m)
        add(l, r, c, m + 1, t, p * 2 + 1);
    sum[p] = sum[p * 2] + sum[p * 2 + 1];
}

// l, r      - 要查询的区间的起点和终点
// s, t      - 当前正在考察的区间的起点和终点
// p         - 当前的节点编号
// sum[]     - 线段树维护区间和
// add_val[] - 加法修改标记
// 如果要对长度为 n 的数列查询 [a, b] 区间的和，则调用 get_sum(a, b, 1, n, 1);
int get_sum(int l, int r, int s, int t, int p)
{
    if (l <= s && t <= r)
        return sum[p];
    int m = s + (t - s) / 2;
    if (add_val[p])
    {
        sum[p * 2] += add_val[p] * (m - s + 1);
        sum[p * 2 + 1] += add_val[p] * (t - m);
        add_val[p * 2] += add_val[p];
        add_val[p * 2 + 1] += add_val[p];
        add_val[p] = 0;
    }
    int ans = 0;
    if (l <= m)
        ans += get_sum(l, r, s, m, p * 2);
    if (r > m)
        ans += get_sum(l, r, m + 1, t, p * 2 + 1);
    return ans;
}
```

### 3.9.2. 维护区间和，包含 + x 运算

```cpp
// s, t      - 建树的区间起点和终点
// p         - 当前的节点编号
// a[]       - 原数组 (1 ~ n)
// sum[]     - 线段树维护区间和
// add_val[] - 加法修改标记
// mul_val[] - 乘法修改标记
// 如果要对长度为 n 的数列建立线段树，则调用 build(1, n, 1);
void build(int s, int t, int p)
{
    mul_val[p] = 1;
    if (s == t)
    {
        sum[p] = a[s];
        return;
    }
    int m = s + (t - s) / 2;
    build(s, m, 2 * p);
    build(m + 1, t, 2 * p + 1);
    sum[p] = sum[2 * p] + sum[2 * p + 1];
}

// p         - 当前的节点编号
// s, t      - 当前正在考察的区间的起点和终点
// sum[]     - 线段树维护区间和
// add_val[] - 加法修改标记
// mul_val[] - 乘法修改标记
void push_down(int p, int s, int t)
{
    int m = s + (t - s) / 2;
    if (mul_val[p] != 1 && s != t)
    {
        sum[p * 2] *= mul_val[p];
        sum[p * 2 + 1] *= mul_val[p];
        add_val[p * 2] *= mul_val[p];
        add_val[p * 2 + 1] *= mul_val[p];
        mul_val[p * 2] *= mul_val[p];
        mul_val[p * 2 + 1] *= mul_val[p];
        mul_val[p] = 1;
    }
    if (add_val[p] && s != t)
    {
        sum[p * 2] += add_val[p] * (m - s + 1);
        sum[p * 2 + 1] += add_val[p] * (t - m);
        add_val[p * 2] += add_val[p];
        add_val[p * 2 + 1] += add_val[p];
        add_val[p] = 0;
    }
}

// l, r      - 要更新的区间的起点和终点
// c         - 更新值 +c
// s, t      - 当前正在考察的区间的起点和终点
// p         - 当前的节点编号
// 如果要对长度为 n 的数列的 [a, b] 区间 +c，则调用 add(a, b, c, 1, n, 1);
void add(int l, int r, int c, int s, int t, int p)
{
    if (l <= s && t <= r)
    {
        sum[p] += (t - s + 1) * c;
        add_val[p] += c;
        return;
    }
    push_down(p, s, t);
    int m = s + (t - s) / 2;
    if (l <= m)
        add(l, r, c, s, m, p * 2);
    if (r > m)
        add(l, r, c, m + 1, t, p * 2 + 1);
    sum[p] = sum[p * 2] + sum[p * 2 + 1];
}

// l, r      - 要更新的区间的起点和终点
// c         - 更新值 *c
// s, t      - 当前正在考察的区间的起点和终点
// p         - 当前的节点编号
// 如果要对长度为 n 的数列的 [a, b] 区间 *c，则调用 mul(a, b, c, 1, n, 1);
void mul(int l, int r, int c, int s, int t, int p)
{
    if (l <= s && t <= r)
    {
        sum[p] *= c ;
        add_val[p] *= c;
        mul_val[p] *= c;
        return;
    }
    push_down(p, s, t);
    int m = s + (t - s) / 2;
    if (l <= m)
        mul(l, r, c, s, m, p * 2);
    if (r > m)
        mul(l, r, c, m + 1, t, p * 2 + 1);
    sum[p] = sum[p * 2] + sum[p * 2 + 1];
}

// l, r - 要查询的区间的起点和终点
// s, t - 当前正在考察的区间的起点和终点
// p    - 当前的节点编号
// 如果要对长度为 n 的数列查询 [a, b] 区间的和，则调用 get_sum(a, b, 1, n, 1);
int get_sum(int l, int r, int s, int t, int p)
{
    if (l <= s && t <= r)
        return sum[p];
    push_down(p, s, t);
    int m = s + (t - s) / 2;
    int ans = 0;
    if (l <= m)
        ans += get_sum(l, r, s, m, p * 2);
    if (r > m)
        ans += get_sum(l, r, m + 1, t, p * 2 + 1);
    return ans;
}
```

### 3.9.3. 维护区间和，包含修改运算

```cpp
// l, r      - 要更新的区间的起点和终点
// c         - 更新值 +c
// s, t      - 当前正在考察的区间的起点和终点
// p         - 当前的节点编号
// sum[]     - 线段树维护区间和
// upd_tag[] - 修改标记
// upd_val[] - 修改值
// 如果要将长度为 n 的数列的 [a, b] 区间改为 c，则调用 update(a, b, c, 1, n, 1);
void update(int l, int r, int c, int s, int t, int p)
{
    if (l <= s && t <= r)
    {
        sum[p] = (t - s + 1) * c;
        upd_tag[p] = 1;
        upd_val[p] = c;
        return;
    }
    int m = s + (t - s) / 2;
    if (upd_tag[p] && s != t)
    {
        sum[p * 2] = upd_val[p] * (m - s + 1);
        sum[p * 2 + 1] = upd_val[p] * (t - m);
        upd_val[p * 2] = upd_val[p];
        upd_val[p * 2 + 1] = upd_val[p];
        upd_tag[p * 2] = 1;
        upd_tag[p * 2 + 1] = 1;
        upd_tag[p] = 0;
    }
    if (l <= m)
        update(l, r, c, s, m, p * 2);
    if (r > m)
        update(l, r, c, m + 1, t, p * 2 + 1);
    sum[p] = sum[p * 2] + sum[p * 2 + 1];
}

// l, r      - 要查询的区间的起点和终点
// s, t      - 当前正在考察的区间的起点和终点
// p         - 当前的节点编号
// sum[]     - 线段树维护区间和
// upd_tag[] - 修改标记
// upd_val[] - 修改值
// 如果要对长度为 n 的数列查询 [a, b] 区间的和，则调用 get_sum(a, b, 1, n, 1);
int get_sum(int l, int r, int s, int t, int p)
{
    if (l <= s && t <= r)
        return sum[p];
    int m = s + (t - s) / 2;
    if (upd_tag[p])
    {
        sum[p * 2] = upd_val[p] * (m - s + 1);
        sum[p * 2 + 1] = upd_val[p] * (t - m);
        upd_val[p * 2] = upd_val[p];
        upd_val[p * 2 + 1] = upd_val[p];
        upd_tag[p * 2] = 1;
        upd_tag[p * 2 + 1] = 1;
        upd_tag[p] = 0;
    }
    int ans = 0;
    if (l <= m)
        ans += get_sum(l, r, s, m, p * 2);
    if (r > m)
        ans += get_sum(l, r, m + 1, t, p * 2 + 1);
    return ans;
}
```

# 4. 数论

## 4.1. 模逆元

$ab\equiv1\pmod p$，知 $a,p$ 求 $b$.

- $a,p$ 不互质：不存在逆元
- $a,p$ 互质
  - $p$ 为质数：费马小定理 $b=a^{p-2}\pmod p$，用快速幂算。
  - $p$ 为合数：扩展欧几里得算法求逆元。**（千万不可直接快速幂）**

## 4.2. 算术基本定理

定理：任何一个大于 $1$ 的自然数 $N$，如果 $N$ 不为质数，那么 $N$ 可以唯一分解成有限个质数的乘积 $N=P_1^{a_1}P_2^{a_2}P_3^{a_3}\cdots P_n^{a_n}$，$P_1<P_2<P_3<\cdots<P_n$ 且均为质数，$a_1,a_2,a_3,\cdots,a_n$ 均为正整数。 

推论：一个大于 $1$ 的整数 $N$，如果它的标准分解式为 $N=P_1^{a_1}P_2^{a_2}P_3^{a_3}\cdots P_n^{a_n}$，那么它的正因数个数为 $\sigma_0(N)=(1+a_1)(1+a_2)\cdots(1+a_n)$

### 4.2.1. 求正因数个数

```cpp
bool is_prime[SIZE];
int prime[SIZE], primesize = 0;
// 欧拉筛生成质数代码省略
int fact_cnt(int n)
{
	int now = n, ans = 1;
	for (int i = 0; i < primesize && prime[i] <= sqrt(now); i++)
	{
		int cnt = 0;
		while (now % prime[i] == 0)
		{
			cnt++;
			now /= prime[i];
		}
		ans *= (cnt + 1);
	}
	if (now != 1)
		ans *= 1 + 1;
	return ans;
}
```

### 4.2.2. 判断正因数之和奇偶性

需要以下结论：

- 奇数个奇数相加为奇数，偶数个奇数相加为偶数
- 奇数乘奇数为奇数，奇数乘偶数为偶数，偶数乘偶数为偶数
- 除了 $2$，质数均为奇数。因此除了 $2$，质数的任意次幂都是奇数。

假设 $\sigma_1(N)=(1+P_1+P_1^2+\cdots+P_1^{a_1})(1+P_2+P_2^2+\cdots+P_2^{a_2})\cdots(1+P_n+P_n^2+\cdots+P_n^{a_n})$ 为奇数，那么：

**情况 1：**若 $2\mid N$，那么 $P_1=2$，所以 $P_1+P_1^2+\cdots+P_1^{a_1}$ 为偶数，$1+P_1+P_1^2+\cdots+P_1^{a_1}$ 为奇数。

如果 $\sigma_1(N)$ 为奇数，那么 $(1+P_2+P_2^2+\cdots+P_2^{a_2}),\cdots,(1+P_n+P_n^2+\cdots+P_n^{a_n})$ 均为奇数

即 $(P_2+P_2^2+\cdots+P_2^{a_2}),\cdots,(P_n+P_n^2+\cdots+P_n^{a_n})$ 均为偶数

因为 $P_2,\cdots,P_n$ 均为质数，由结论可知，一定是偶数个奇数相加，即 $a_2,\cdots,a_n$ 均为偶数

**情况 1.1：**若 $a_1$ 为偶数，$N=P_1^{a_1}\cdot P_2^{a_2}\cdot P_3^{a_3}\cdots P_n^{a_n}=(P_1^{a_1/2}\cdot P_2^{a_2/2}\cdot P_3^{a_3/2}\cdots P_n^{a_n/2})^2$ 为完全平方数 $x^2$

**情况 1.2：**若 $a_1$ 为奇数， $N=P_1^{a_1}\cdot P_2^{a_2}\cdot P_3^{a_3}\cdots P_n^{a_n}=P_1\times(P_1^{(a_1-1)/2}\cdot P_2^{a_2/2}\cdot P_3^{a_3/2}\cdots P_n^{a_n/2})^2$ 为完全平方数的两倍 $2\cdot x^2$

**情况 2：**若 $2\nmid N$，同上得 $(P_1+P_1^2+\cdots+P_1^{a_2}),\cdots,(P_n+P_n^2+\cdots+P_n^{a_n})$ 均为偶数

所以 $N=P_1^{a_1}\cdot P_2^{a_2}\cdot P_3^{a_3}\cdots P_n^{a_n}=(P_1^{a_1/2}\cdot P_2^{a_2/2}\cdot P_3^{a_3/2}\cdots P_n^{a_n/2})^2$ 为完全平方数 $x^2$

**综上所述：**若 $N=x^2\ 或\ 2\cdot x^2$，$\sigma_1(N)$ 为奇数，反之为偶数。

代码实现非常简单，略去。

## 4.3. 欧拉函数

对正整数 $n$，欧拉函数是小于 $n$ 的正整数中与 $n$ 互质的数的数目，记作 $\varphi(n)$。

若 $n$ 有标准分解 $p_1^{k_1}p_2^{k_2}\cdots p_r^{k_r}$，其中 $p_i$ 为互异的质因子，$k_i\geq1$ 为质因子的次数。则欧拉函数的值为：
$$
\varphi(n)=n(1-\frac{1}{p_1})(1-\frac{1}{p_2})\cdots(1-\frac{1}{p_r})
$$
需要注意：$\varphi(1)=1$

### 4.3.1. 朴素法

时间复杂度：$O(\sqrt{n})$ 

该方法仅求得 $n$ 的欧拉函数值

```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    cin >> a;
    int ans = a;
    for (int i = 2; i <= a / i; i++)
    {
        if (!(a % i))
        {
            ans = ans / i * (i - 1);
            while (!(a % i))
                a /= i;
        }
    }
    if (a > 1)
        ans = ans / a * (a - 1);
    cout << ans << endl;
    return 0;
}
```

### 4.3.2. 线性筛法

时间复杂度：$O(n)$

该方法求得 $1\sim n$ 的所有欧拉函数值

```cpp
const int MAXN = 1e6 + 10;
int prime[MAXN], phi[MAXN], idx;
bool is_prime[MAXN];

void init(int n)
{
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            prime[idx++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < idx && i * prime[j] <= n; j++)
        {
            is_prime[i * prime[j]] = false;
            if (!(i % prime[j]))
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}
```

## 4.4. 扩展欧几里得算法 Extended Euclidean algorithm

```cpp
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
```

```cpp
// 求模数非质数的乘法逆元
int inv(int a, int p)
{
    int x, y;
    if (exgcd(a, p, x, y) != 1)
        return -1; // 无解
    return (x % p + p) % p;
}
```

## 4.5. 扩展中国剩余定理 exCRT

有以下一元线性同余方程组：
$$
(S) : \quad \left\{ \begin{matrix} x \equiv a_1 \pmod {m_1} \\ x \equiv a_2 \pmod {m_2} \\ \vdots \qquad\qquad\qquad \\ x \equiv a_n \pmod {m_n} \end{matrix} \right.
$$

**不保证**整数 $m_1,m_2,\dots,m_n$ 其中任两数互质，问：方程组是否有解？若有解，试求 $x$.

```cpp
typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// 如果中途输出-1, -1则需要立即停止
// first-a second-mod
pair<ll, ll> excrt(pair<ll, ll> a, pair<ll, ll> b)
{
    ll ya, yb;
    ll d = exgcd(a.second, b.second, ya, yb);
    if ((b.first - a.first) % d)
        return {-1, -1};
    ya *= (b.first - a.first) / d;
    ll tmp = b.second / d;
    ya = (ya % tmp + tmp) % tmp;
    a.first += a.second * ya;
    a.second = a.second / d * b.second;
    return a;
}
```

## 4.6. 高斯消元法 Gaussian Elimination

```cpp
const int MAXN = 110;     // 最大方程数
const double EPS = 1e-6;  // 浮点误差
int n;                    // 方程个数
double mat[MAXN][MAXN];   // 增广矩阵

int gauss()
{
    int row, col;
    for (row = 0, col = 0; col < n; col++)
    {
        int max_row = row;
        for (int i = row; i < n; i++)
            if (fabs(mat[i][col]) > fabs(mat[max_row][col]))
                max_row = i;
        if (fabs(mat[max_row][col]) < EPS)
            continue;
        for (int i = col; i <= n; i++)
            swap(mat[max_row][i], mat[row][i]);
        for (int i = n; i >= col; i--)
            mat[row][i] /= mat[row][col];
        for (int i = row + 1; i < n; i++)
            if (fabs(mat[i][col]) > EPS)
                for (int j = n; j >= col; j--)
                    mat[i][j] -= mat[i][col] * mat[row][j];
        row++;
    }
    if (row < n)
    {
        for (int i = row; i < n; i++)
            if (fabs(mat[i][n]) > EPS)
                return 2; // 无解
        return 1; // 无穷解
    }
    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            mat[i][n] -= mat[i][j] * mat[j][n];
    return 0; // 有唯一解
}
```

## 4.7. 组合数

### 4.7.1. 公式法

$$
C_n^k={n\choose k}=\frac{P_{k}^{n}}{k!}=\frac{n!}{k!(n-k)!}
$$

时间复杂度：$O(n\log p)$ (预处理阶乘和逆元) ，$O(1)$ (得到组合数)

```cpp
long long fast_pow(long long, long long) // 快速幂
long long inv(long long); // 求逆元

void init()
{
    fact[0] = invf[0] = 1;
    for (int i = 1; i < MAXA; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = invf[i - 1] * inv(i) % MOD;
    }
}

int main()
{
    init();
    long long a, b;
    cin >> a >> b;
    cout << fact[a] * invf[b] % MOD * invf[a - b] % MOD << endl;
    return 0;
}
```

### 4.7.2. 递推法

$$
C_n^k=C_{n-1}^{k}+C_{n-1}^{k-1}
$$

时间复杂度：$O(n^2)$

```cpp
const int MAXA = 2010;
const long long MOD = 1e9 + 7;
long long ans[MAXA][MAXA];

void init()
{
    for (int i = 0; i < MAXA; i++)
        ans[i][0] = 1;
    for (int i = 1; i < MAXA; i++)
        for (int j = 1; j < MAXA; j++)
            ans[i][j] = (ans[i - 1][j] + ans[i - 1][j - 1]) % MOD;
}
```

### 4.7.3. 卢卡斯定理

$$
C_{m}^{n}\equiv C_{m/p}^{n/p}\cdot C_{m\bmod p}^{n\bmod p}\pmod p
$$

时间复杂度：$O(p\log p\cdot\log_p{n})$

```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAXA = 1e5 + 10;
long long fact[MAXA];

void init(int mod)
{
    fact[0] = 1;
    for (int i = 1; i <= mod; i++)
        fact[i] = fact[i - 1] * i % mod;
}

long long fast_pow(long long a, long long b, long long p)
{
    b %= p;
    long long ans = 1;
    while (b)
    {
        if (b % 2)
            ans = a * ans % p;
        a = a * a % p;
        b /= 2;
    }
    return ans;
}

inline long long inv(long long x, long long p)
{
    return fast_pow(x, p - 2, p);
}

long long comb(long long a, long long b, long long p)
{
    if (b > a)
        return 0;
    if (a < p && b < p)
        return fact[a] * inv(fact[b], p) % p * inv(fact[a - b], p) % p;
    return comb(a % p, b % p, p) * comb(a / p, b / p, p) % p;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long a, b, p;
        cin >> a >> b >> p;
        init(p);
        cout << comb(a, b, p) << endl;
    }
    return 0;
}
```

### 4.7.4. 高精度算法

```py
a, b = input().split(' ')
a = int(a)
b = int(b)
res = 1
for i in range(a - b + 1, a + 1):
    res *= i
for i in range(1, b + 1):
    res //= i
print(res)
```

## 4.8. 容斥原理

$$
{\displaystyle {\begin{aligned}\left|\bigcup _{i=1}^{n}A_{i}\right|={}&\sum _{i=1}^{n}|A_{i}|-\sum _{1\leq i<j\leq n}|A_{i}\cap A_{j}|+\sum _{1\leq i<j<k\leq n}|A_{i}\cap A_{j}\cap A_{k}|-\cdots +(-1)^{n-1}\left|A_{1}\cap \cdots \cap A_{n}\right|.\end{aligned}}}
$$

```cpp
for (int i = 1; i < (1 << n); i++)
    for (int j = 0; j < n; j++)
        if (i >> j & 1)
            ...
```

## 4.9. 哥德巴赫猜想 Goldbach Conjecture

- 任一大于 $2$ 的偶数，都可表示成两个素数之和。
- 大于 $5$ 的奇数都可以表示成三个素数之和。
- 任意一个大于 $4$ 的偶数都可以拆成两个奇素数之和。