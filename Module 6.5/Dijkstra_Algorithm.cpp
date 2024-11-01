#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int, int>> adj[105];
    int n, s, f;
    cin >> n >> s >> f;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x > 0)
            {
                adj[i].push_back({j, x});
            }
        }
    }

    int dis[n];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    queue<pair<int, int>> q;
    q.push({s, 0});
    dis[s] = 0;
    while (!q.empty())
    {
        int Node = q.front().first;
        int cost = q.front().second;
        q.pop();
        for (pair<int, int> x : adj[Node])
        {
            int childNode = x.first;
            int childCost = x.second;
            if (cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                q.push({childNode, dis[childNode]});
            }
        }
    }
    if (dis[f] == INT_MAX)
        cout << -1 << endl;
    else
        cout << dis[f] << endl;
    return 0;
}