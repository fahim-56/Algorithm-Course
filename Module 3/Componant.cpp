#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> v[N];
bool vis[N] = {false};
void DFS(int src)
{
    cout << src << endl;
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
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            DFS(i);
        }
    }
    return 0;
}