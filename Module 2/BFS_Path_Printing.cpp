#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> a[n];
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    cout << "Enter Source :" << endl;
    int src;
    cin >> src;
    queue<int> q;
    vector<bool> visited(n, false);
    vector<int> level(n, -1);
    vector<int> parent(n, -1);
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        for (int x : a[q.front()])
        {
            if (visited[x] == false)
            {
                q.push(x);
                visited[x] = true;
                level[x] = level[q.front()] + 1;
                parent[x] = q.front();
            }
        }
        q.pop();
    }
    cout << "Destination Value :" << endl;
    int k;
    cin >> k;
    vector<int> Des_Print;
    while (k != -1)
    {
        Des_Print.push_back(k);
        k = parent[k];
    }
    reverse(Des_Print.begin(), Des_Print.end());
    for (int x : Des_Print)
    {
        cout << x << " ";
    }
    return 0;
}