#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
vector<int> adj[N];
bool vis[N];
int par[N];
bool flag = false;
void DFS(vector<int> adj[], int src)
{
    vis[src] = true;
    for (int child : adj[src])
    {
        if (vis[child] && par[src] != child)
        {
            flag = true;
        }
        if (!vis[child])
        {
            par[child] = src;
            DFS(adj, child);
        }
    }
}
bool isCycle(int V, vector<int> adj[])
{
    memset(vis, false, sizeof(vis));
    memset(par, -1, sizeof(par));
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            DFS(adj, i);
    }
    return flag;
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (isCycle(n, adj))
        cout << "YES";
    else
        cout << "No";

    return 0;
}