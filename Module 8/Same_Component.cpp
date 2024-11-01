#include <bits/stdc++.h>
using namespace std;
int n, m;
char grid[1005][1005];
bool valid(int i, int j)
{
    return (i < n && i >= 0 && j < m && j >= 0);
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            grid[i][j] = ch;
        }
    }
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    queue<pair<int, int>> q;
    vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool vis[n][m];
    memset(vis, false, sizeof(vis));
    q.push({si, sj});
    vis[si][sj] = true;
    bool flag = false;
    while (!q.empty())
    {
        if (q.front().first == di && q.front().second == dj)
        {
            flag = true;
            break;
        }
        // cout << q.front().first << " " << q.front().second << endl;
        for (int i = 0; i < 4; i++)
        {
            for (pair<int, int> x : d)
            {
                int ci = q.front().first + x.first;
                int cj = q.front().second + x.second;
                if (valid(ci, cj) && grid[ci][cj] != '-' && !vis[ci][cj])
                {
                    q.push({ci, cj});
                    vis[ci][cj] = true;
                }
            }
        }
        q.pop();
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}