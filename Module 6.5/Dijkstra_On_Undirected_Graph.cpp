#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj[1005];
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dis;
    for (int i = 0; i < V; i++)
    {
        dis.push_back(INT_MAX);
    }
    queue<pair<int, int>> q;
    q.push({S, 0});
    dis[S] = 0;
    while (!q.empty())
    {
        pair<int, int> x = q.front();
        int parrent = x.first;
        int cost = x.second;
        q.pop();
        for (vector<int> child : adj[parrent])
        {
            int childNode = child[0];
            int childCost = child[1];
            if (cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                q.push({childNode, dis[childNode]});
            }
        }
    }
    return dis;
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    vector<int> v = dijkstra(n, adj, 0);
    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}