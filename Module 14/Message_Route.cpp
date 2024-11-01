#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> arr[n + 1];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    bool vis[n + 1];
    memset(vis, false, sizeof(vis));

    int par[n + 1];
    memset(par, -1, sizeof(par));

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty())
    {
        int src = q.front();
        q.pop();
        for (int x : arr[src])
        {
            if (!vis[x])
            {
                q.push(x);
                vis[x] = true;
                par[x] = src;
            }
        }
    }
    if (par[n] == -1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<int> v;
    while (n != -1)
    {
        v.push_back(n);
        n = par[n];
    }
    cout << v.size() << endl;
    reverse(v.begin(), v.end());
    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}