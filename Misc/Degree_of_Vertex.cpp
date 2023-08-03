#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1e4 + 1;          // 图的最大顶点数，编号1~SIZE（编号0保留）
vector<pair<int, int>> Edge[SIZE]; // 储存图的边，vector数组下标为起点，二元组的第一位为边的编号，第二位为边的终点
int cntVertex;                     // 顶点数
int cntEdge;                       // 边数

void addEdge(int id, int start, int end)
{
    // 由于是无向图，因此需要储存正反边
    Edge[start].push_back({id, end});
    Edge[end].push_back({id, start});
}

int main()
{
    cout << "============================" << endl
         << "实验22  求无向图中顶点的度数" << endl
         << "============================" << endl;
    // 设置图的边数和顶点数
    cout << "输入图的顶点数：";
    cin >> cntVertex;
    cout << "输入图的边数：";
    cin >> cntEdge;
    // 读入图的边的两个顶点
    for (int i = 1; i <= cntEdge; i++)
    {
        while (true)
        {
            int start, end;
            cout << "输入第" << i << "条边的顶点：";
            cin >> start >> end;
            // 顶点要在1~cntVertex范围内
            if (start > 0 && start <= cntVertex && end > 0 && end <= cntVertex)
            {
                addEdge(i, start, end);
                break;
            }
            else
            {
                cout << "输入边不合法，请重输" << endl;
            }
        }
    }
    // 计算度数
    for (int i = 1; i <= cntVertex; i++)
    {
        cout << "============================" << endl;
        cout << "顶点" << i << "的度数为：" << Edge[i].size() << endl;
        set<int> vis;
        for (auto e : Edge[i])
        {
            if (vis.find(e.first) != vis.end())
                continue;
            vis.insert(e.first);
            cout << "V" << i << " <---E" << e.first << "---> V" << e.second << endl;
        }
    }
    return 0;
}