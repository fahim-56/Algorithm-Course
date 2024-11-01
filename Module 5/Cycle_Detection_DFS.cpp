#include <bits/stdc++.h>
using namespace std;
vector<int> arr[10005];
bool vis[10005];
int parentArray[10005];
bool flag = false;
void DFS(int parent)
{
    vis[parent] = true;
    for (int child : arr[parent])
    {
        if (vis[child] && parentArray[parent] != child)
        {
            flag = true;
        }
        if (!vis[child])
        {
            parentArray[child] = parent;
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
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parentArray, -1, sizeof(parentArray));
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            DFS(i);
    }
    if (flag)
        cout << "Cycle Detected" << endl;
    else
        cout << "Cycle Not Detected" << endl;
    return 0;
}
// 7 6
// 0 1
// 0 2
// 3 4
// 4 5
// 5 6
// 6 3