#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[1005];
int dis[1005];
class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
void Dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    q.push({src, 0});
    dis[src] = 0;
    while (!q.empty())
    {
        // cout << q.top().first << " " << q.top().second << endl;
        for (pair<int, int> child : adj[q.top().first])
        {
            if (q.top().second + child.second < dis[child.first])
            {
                dis[child.first] = q.top().second + child.second;
                q.push({child.first, dis[child.first]});
            }
        }
        q.pop();
    }
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
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    int src;
    cin >> src;
    Dijkstra(src);
    for (int i = 0; i < n; i++)
    {
        cout << dis[i] << endl;
    }

    return 0;
}