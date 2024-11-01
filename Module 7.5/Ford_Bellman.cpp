#include <bits/stdc++.h>
using namespace std;
class edge
{
public:
    int u, v, c;
    edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    int dis[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[1] = 0;
    vector<edge> elist;
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        elist.push_back(edge(u, v, c));
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (edge ed : elist)
        {
            if (dis[ed.u] < INT_MAX && dis[ed.u] + ed.c < dis[ed.v])
            {
                dis[ed.v] = dis[ed.u] + ed.c;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] == INT_MAX)
        {
            cout << 30000 << " ";
            continue;
        }
        cout << dis[i] << " ";
    }

    return 0;
}