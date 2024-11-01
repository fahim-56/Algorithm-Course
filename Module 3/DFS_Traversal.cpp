#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> v[N];
bool vis[N] = {false};
void DFS(int n)
{
    cout << n << " ";
    vis[n] = true;
    for (int child : v[n])
    {
        if (!vis[child])
        {
            DFS(child);
        }
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
    cout << "Enter source node" << endl;
    cin >> src;
    DFS(src);
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