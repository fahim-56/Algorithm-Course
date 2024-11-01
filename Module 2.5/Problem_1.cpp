#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> a[n + 1];
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int k;
    cin >> k;
    while (k--)
    {
        vector<int> parent(n + 1, -1);
        int src, des;
        cin >> src >> des;
        queue<int> q;
        vector<bool> visited(n + 1, false);
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            for (int i = 0; i < a[q.front()].size(); i++)
            {
                if (visited[a[q.front()][i]] == false)
                {
                    q.push(a[q.front()][i]);
                    visited[a[q.front()][i]] = true;
                    parent[a[q.front()][i]] = q.front();
                }
            }
            q.pop();
        }
        int cnt = 0;
        if (visited[des] == false)
        {
            cout << -1 << endl;
            continue;
        }
        while (des != src)
        {
            des = parent[des];
            cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}