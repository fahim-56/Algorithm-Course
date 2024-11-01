#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int x : adj[i])
    //         cout << x << " ";
    //     cout << endl;
    // }
    bool vis[n + 1];
    int parent[n + 1];
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty())
    {
        for (int x : adj[q.front()])
        {
            if (!vis[x])
            {
                q.push(x);
                vis[x] = true;
                parent[x] = q.front();
            }
        }
        q.pop();
    }
    if (!vis[n])
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    int cnt = 0;
    vector<int> v;
    if (vis[n])
    {
        while (n != -1)
        {
            cnt++;
            v.push_back(n);
            n = parent[n];
        }
    }
    cout << cnt << endl;
    reverse(v.begin(), v.end());
    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}