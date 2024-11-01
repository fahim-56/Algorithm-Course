#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
int main()
{
    // cout << "Enter The Number of Node & Edge: " << endl;
    int n, e;
    cin >> n >> e;
    int dis[n];
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    vector<Edge> edjeList;
    // cout << "Enter The Number of Nodes & Edges between Nodes : " << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        Edge obj(u, v, c);
        edjeList.push_back(obj);
    }
    // cout << "Enter The source Node" << endl;
    int src;
    cin >> src;
    dis[src] = 0;
    for (int i = 0; i < n; i++)
    {
        for (Edge x : edjeList)
        {
            if (dis[x.u] < INT_MAX && dis[x.u] + x.c < dis[x.v])
            {
                dis[x.v] = dis[x.u] + x.c;
            }
        }
    }
    bool cycle = false;
    for (Edge x : edjeList)
    {
        if (dis[x.u] < INT_MAX && dis[x.u] + x.c < dis[x.v])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Negetive cycle detected" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (dis[i] == INT_MAX)
            {
                cout << i << " Is Not Conected" << endl;
                continue;
            }
            cout << i << " ->" << dis[i] << endl;
        }
    }
    return 0;
}
