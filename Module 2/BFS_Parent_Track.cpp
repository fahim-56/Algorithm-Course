#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> ar[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    queue<int> q;
    vector<bool> vis(n, false);
    int src;
    cin >> src;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        cout << q.front() << " ";
        for (int x : ar[q.front()])
        {
            if (!vis[x])
            {
                q.push(x);
                vis[x] = true;
            }
        }
        q.pop();
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