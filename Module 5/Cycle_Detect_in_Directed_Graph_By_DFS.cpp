#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10005];
bool vis[10005];
bool same_path[10005];
int flag = true;
int cnt = 0;
void DFS(int parent)
{
    vis[parent] = true;
    same_path[parent] = true;
    for (int child : adj[parent])
    {
        if (same_path[child])
        {
            cnt++;
            cout << "Cycle Ditected at " << child << endl;
            flag = false;
        }
        if (!vis[child])
        {
            DFS(child);
        }
    }
    same_path[parent] = false;
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    memset(vis, false, sizeof(vis));
    memset(same_path, false, sizeof(same_path));
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
            DFS(i);
    }
    if (flag)
        cout << "Cycle Not Detected" << endl;
    cout << cnt;
    return 0;
}
