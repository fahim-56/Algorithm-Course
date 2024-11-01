#include <bits/stdc++.h>
using namespace std;
vector<int> v[10005];
bool vis[1005] = {false};
int N;
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
    int src;
    cin >> src;
    DFS(src);
    cout << N << endl;
    return 0;
}