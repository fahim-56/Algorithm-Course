#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> arr[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    int src;
    cin >> src;
    queue<int> q;
    vector<bool> vis(n, false);
    vector<int> level(n, -1);
    vector<int> parent(n, -1);
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        for (int x : arr[q.front()])
        {
            if (vis[x] == false)
            {
                q.push(x);
                vis[x] = true;
                level[x] = level[q.front()] + 1;
                parent[x] = q.front();
            }
        }
        q.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << level[i] << " - " << parent[i] << endl;
    }
    cout << "Which is your destination :" << endl;
    int des;
    cin >> des;
    vector<int> path;
    while (des != -1)
    {
        path.push_back(des);
        des = parent[des];
    }
    reverse(path.begin(), path.end());
    for (int x : path)
    {
        cout << x << " ";
    }
    // 6 6
    // 3 0
    // 0 1
    // 0 2
    // 1 2
    // 2 4
    // 4 5
    // 0
    return 0;
}