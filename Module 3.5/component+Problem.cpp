#include <bits/stdc++.h>
using namespace std;
vector<int> v;
bool vis[10005] = {false};
void DFS(vector<int> adj[], int src)
{
    v.push_back(src);
    vis[src] = true;
    for (int x : adj[src])
    {
        if (vis[x] == false)
        {
            DFS(adj, x);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    DFS(adj, 0);
    return v;
}
int main()
{

    return 0;
}