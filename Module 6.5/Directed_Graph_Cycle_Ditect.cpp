#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
bool vis[100005];
bool path[100005];
bool flag = false;
void DFS(vector<int> adj[], int src)
{
    vis[src] = true;
    path[src] = true;
    for (int child : adj[src])
    {
        if (vis[child] && path[child])
        {
            flag = true;
        }
        if (!vis[child])
            DFS(adj, child);
    }
    path[src] = false;
}
bool isCyclic(int V, vector<int> adj[])
{
    memset(vis, false, sizeof(vis));
    memset(path, false, sizeof(path));
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
    }
    if (isCyclic(n, adj))
        cout << "Cycle ditected" << endl;
    else
        cout << "Cycle Not ditected" << endl;

    return 0;
}