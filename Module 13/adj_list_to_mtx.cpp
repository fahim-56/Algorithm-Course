#include <bits/stdc++.h>
using namespace std;
void convert_To_mtx(int V, vector<int> adj[])
{
    int mtx[V][V];
    memset(mtx, 0, sizeof(mtx));
    for (int i = 0; i < V; i++)
    {
        for (int x : adj[i])
        {
            mtx[i][x] = 1;
        }
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << mtx[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        // Undirected Graph
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    convert_To_mtx(n, adj);
    return 0;
}
// 5 5
// 0 2
// 1 2
// 1 4
// 2 4
// 2 3