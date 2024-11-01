#include <bits/stdc++.h>
using namespace std;
class cmp
{
public:
    bool operator()(pair<long long int, long long int> a, pair<long long int, long long int> b)
    {
        return a.second > b.second;
    }
};
int main()
{
    long long int n, e;
    cin >> n >> e;
    vector<pair<int, int>> adj[n + 1];
    while (e--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    long long int src;
    cin >> src;
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, cmp> q;
    long long int dis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    q.push({src, 0});
    dis[src] = 0;
    while (!q.empty())
    {
        for (pair<long long int, long long int> x : adj[q.top().first])
        {
            long long int childNode = x.first;
            long long int childCost = x.second;
            if (q.top().second + childCost < dis[childNode])
            {
                dis[childNode] = q.top().second + childCost;
                q.push({childNode, dis[childNode]});
            }
        }
        q.pop();
    }

    int t;
    cin >> t;
    while (t--)
    {
        long long int d, dw;
        cin >> d >> dw;
        if (dis[d] <= dw)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}