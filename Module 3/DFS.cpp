#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> a[N];
bool visited[N] = {false};

void DFS(int src)
{
    cout << src << endl;
    visited[src] = true;
    for (int child : a[src])
    {
        if (visited[child] == false)
            DFS(child);
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    cout << "Enter the node and its Child Node :" << endl;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int src;
    cout << "Enter the source Node :" << endl;
    cin >> src;
    DFS(src);
    return 0;
}