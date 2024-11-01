#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n+1];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int src, des;
        cin >> src >> des;
        queue<int> que;
        vector<bool> vis(n + 1, false);
        vector<int> par(n + 1, -1);
        que.push(src);
        vis[src] = true;
        while (!que.empty())
        {
            for (int x : adj[que.front()])
            {
                if (vis[x] == false)
                {
                    que.push(x);
                    vis[x] = true;
                    par[x] = que.front();
                }
            }
            que.pop();
        }
        int cnt = 0;
        if (vis[des] == false)
        {
            cout << -1 << endl;
            continue;
        }
        while (des != -1)
        {
            cnt++;
            des = par[des];
        }
        cout << cnt - 1 << endl;
    }

    return 0;
}