#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[n + 1];
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    queue<int> q;
    q.push(0);
    vector<bool> visited(n + 1, false);
    vector<int> level(n, -1);
    level[0] = 0;
    visited[0] = true;
    while (!q.empty())
    {
        for (int x : adj_list[q.front()])
        {
            if (visited[x] == false)
            {
                q.push(x);
                // cout << q.front() << " ";
                level[x] = level[q.front()] + 1;
                visited[x] = true;
            }
        }
        q.pop();
    }
    int l;
    cin >> l;
    vector<int> level_val;
    for (int i = 0; i < level.size(); i++)
    {
        if (level[i] == l)
        {
            level_val.push_back(i);
        }
    }
    sort(level_val.begin(), level_val.end(), greater<int>());
    for (int x : level_val)
    {
        cout << x << " ";
    }
    return 0;
}