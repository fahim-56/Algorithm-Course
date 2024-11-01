#include <bits/stdc++.h>
using namespace std;
class edge
{
public:
    int u, v, w;
    edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> adj[n];
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // Undirected Graph
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " -> ";
    //     for (pair<int, int> x : adj[i])
    //     {
    //         cout << x.first << " " << x.second << " ,";
    //     }
    //     cout << endl;
    // }

    vector<edge> edgelist;
    for (int i = 0; i < n; i++)
    {
        for (pair<int, int> x : adj[i])
        {
            edgelist.push_back(edge(i, x.first, x.second));
        }
    }
    cout << "Edge List :" << endl;
    for (edge ed : edgelist)
    {
        cout << ed.u << " " << ed.v << " " << ed.w << endl;
    }

    return 0;
}
// 4 4
// 0 1 10
// 1 2 11
// 3 2 12
// 3 1 13