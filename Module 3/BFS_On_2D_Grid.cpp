#include <bits/stdc++.h>
using namespace std;
int n, m;
bool valid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
        return true;
    return false;
}
int main()
{
    cin >> n >> m;
    char v[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            v[i][j] = '.';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    int si, sj;
    cin >> si >> sj;
    queue<pair<int, int>> q;
    bool vis[n][m];
    memset(vis, false, sizeof(vis));
    q.push({si, sj});
    vis[si][sj] = true;
    vector<pair<int, int>> c = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cout << x << " " << y << endl;
        for (int i = 0; i < 4; i++)
        {
            int ci = x + c[i].first;
            int cj = y + c[i].second;
            if (valid(ci, cj) && vis[ci][cj] == false)
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
            }
        }
    }

    return 0;
}