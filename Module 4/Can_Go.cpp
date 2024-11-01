#include <bits/stdc++.h>
using namespace std;
vector<char> arr[1005];
bool vis[1005][1005];
bool valid(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
bool flag = false;
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
void DFS(int si, int sj, int n, int m)
{
    if (arr[si][sj] == 'B')
    {
        flag = true;
        return;
    }
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + v[i].first;
        int cj = sj + v[i].second;
        if (valid(ci, cj, n, m) && arr[ci][cj] != '#' && vis[ci][cj] == false)
        {
            DFS(ci, cj, n, m);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            arr[i].push_back(ch);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'A')
            {
                DFS(i, j, n, m);
            }
        }
    }
    if (flag == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}