#include <bits/stdc++.h>
using namespace std;
vector<int> arr[10005];
bool vis[10005];
int parent[10005];
bool flag = false;
void BFS(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        for (int child : arr[q.front()])
        {
            if (vis[child] && child != (parent[q.front()]))
            // q.front() er child ar parrent ek kina checking
            {
                flag = true;
            }
            if (!vis[child])
            {
                q.push(child);
                parent[child] = q.front();
                vis[child] = true;
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
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    // 7 6
    // 0 1
    // 0 2
    // 3 4
    // 4 5
    // 5 6
    // 6 3
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            BFS(i);
        }
    }
    if (flag)
        cout << "Cycle detected" << endl;
    else
        cout << "No Cycle available" << endl;
    return 0;
}