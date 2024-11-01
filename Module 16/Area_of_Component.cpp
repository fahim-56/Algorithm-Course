#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char mtx[N][N];
bool vis[N][N];
int n, m;
int cnt;

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int DFS(int si, int sj)
{
    vis[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + p[i].first;
        int cj = sj + p[i].second;
        if (valid(ci, cj) && vis[ci][cj] == false && mtx[ci][cj] == '.')
        {
            DFS(ci, cj);
        }
    }
    return cnt;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mtx[i][j];
            vis[i][j] = false;
        }
    }
    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cnt = 0;
            if (!vis[i][j] && mtx[i][j] == '.')
            {
                DFS(i, j);
            }
            // cout << cnt << endl;
            if (cnt != 0)
                mn = min(mn, cnt);
        }
    }
    if (mn == INT_MAX)
        cout << -1 << endl;
    else
        cout << mn << endl;

    return 0;
}