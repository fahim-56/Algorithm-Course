#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<pair<int, int>> adj[N];
int dis[N];
void Dijkstra(int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;
    while (!q.empty())
    {
        // cout << q.front().first << " " << q.front().second << endl;
        for (pair<int, int> child : adj[q.front().first])
        {
            if (q.front().second + child.second < dis[child.first])
            {
                dis[child.first] = q.front().second + child.second;
                q.push({child.first, dis[child.first]});
            }
        }
        q.pop();
    }
}
int main()
{
    int n, e;
    cout << "Enter the number of Node and Edges" << endl;
    cin >> n >> e;
    cout << "Enter the Nodes and Edges" << endl;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    cout << "Enter the source" << endl;
    int src;
    cin >> src;
    Dijkstra(src);
    cout << "Dis from Node " << src << endl;
    for (int i = 0; i < n; i++)
    {
        cout << dis[i] << endl;
    }
    return 0;
}
// 5 8
// 0 1 10
// 0 2 7
// 0 3 4
// 1 4 3
// 2 4 5
// 2 1 1
// 3 4 5
// 3 2 1
// 0