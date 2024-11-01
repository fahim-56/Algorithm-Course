#include <bits/stdc++.h>
using namespace std;
char v[100][100];
bool vis[100][100];
int cnt = 0;
int n, m;
bool valid(int i, int j)
{
    return (i >= 0 && i < m && j >= 0 && j < n);
}

vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
void DFS(int si, int sj)
{
    vis[si][sj] = true;

    cnt++;

    for (auto x : p)
    {
        int ci = si + x.first;
        int cj = sj + x.second;
        if (valid(ci, cj) && !vis[ci][cj] && v[ci][cj] != '#')
        {
            DFS(ci, cj);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        memset(vis, false, sizeof(vis));
        cout << "Case " << k << ": ";
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }
        cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][j] == '@')
                {
                    DFS(i, j);
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}