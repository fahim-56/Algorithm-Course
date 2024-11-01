#include <bits/stdc++.h>
using namespace std;
vector<int> v[10005];
bool vis[1005] = {false};
void DFS(int src)
{
    vis[src] = true;
    for (int x : v[src])
    {
        if (vis[x] == false)
            DFS(x);
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
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            DFS(i);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}