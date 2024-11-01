#include <bits/stdc++.h>
using namespace std;
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
        adj[b].push_back(a);
    }
    int x;
    cin >> x;
    queue<int> q;
    vector<bool> vis(n, false);
    vector<int> par(n, -1);
    q.push(x);
    vis[x] = true;
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        for (int x : adj[s])
        {
            if (!vis[x])
            {
                q.push(x);
                vis[x] = true;
                par[x] = s;
            }
        }
    }
    int j;
    cin >> j;
    int k;
    cin >> k;
    int cnt = 0;
    if (vis[j] == false)
    {
        cout << "NO" << endl;
        return 0;
    }
    while (j != -1)
    {
        cnt++;
        j = par[j];
    }
    if ((cnt / 2) <= k)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}