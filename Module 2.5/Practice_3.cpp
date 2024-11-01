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
    queue<int> q;
    vector<bool> vis(n, false);
    q.push(0);
    vis[0] = true;
    vector<int> par(n, -1);
    int cnt = 0;
    int nd;
    cin >> nd;
    while (!q.empty())
    {
        if (q.front() == nd)
        {
            cout << arr[q.front()].size() << endl;
            break;
        }
        for (int x : arr[q.front()])
        {
            if (vis[x] == false)
            {
                q.push(x);
                vis[x] = true;
                par[x] = q.front();
            }
        }
        q.pop();
    }

    return 0;
}