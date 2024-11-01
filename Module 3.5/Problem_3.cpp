#include <bits/stdc++.h>
using namespace std;
vector<int> v[10005];
bool vis[1005] = {false};
int N = 0;
void DFS(int src)
{
    N++;
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
    vector<int> cn;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            DFS(i);
            cn.push_back(N);
            N = 0;
        }
    }
    sort(cn.begin(), cn.end());
    for (int x : cn)
    {
        cout << x << " ";
    }
    return 0;
}