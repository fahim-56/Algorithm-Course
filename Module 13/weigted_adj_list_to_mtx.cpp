#include <bits/stdc++.h>
using namespace std;
void convert_adj_to_mtx(int V, vector<pair<int, int>> adj[])
{
    int mtx[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            mtx[i][j] = -1;
            if (i == j)
                mtx[i][j] = 0;
        }
    }

    for (int i = 0; i < V; i++)
    {
        for (pair<int, int> x : adj[i])
        {
            mtx[i][x.first] = x.second;
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
    vector<pair<int, int>> adj[n];
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    convert_adj_to_mtx(n, adj);
    return 0;
}
// 4 5
// 1 0 5
// 0 2 6
// 3 0 8
// 2 3 7
// 3 2 7