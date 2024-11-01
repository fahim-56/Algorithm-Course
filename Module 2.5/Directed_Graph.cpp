#include <bits/stdc++.h>
using namespace std;
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    queue<int> q;
    vector<int> v;
    vector<bool> vis(V, false);
    q.push(0);
    vis[0] = true;
    while (!q.empty())
    {
        v.push_back(q.front());
        for (int x : adj[q.front()])
        {
            if (vis[x] == false)
            {
                q.push(x);
            }
            vis[x] = true;
        }
        q.pop();
    }
    return v;
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
        adj[a].push_back(b);
    }
    vector<int> v = bfsOfGraph(n, adj);
    return 0;
}