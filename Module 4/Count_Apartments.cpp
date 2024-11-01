#include <bits/stdc++.h>
using namespace std;
vector<char> arr[1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool valid(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void DFS(int si, int sj, int n, int m)
{
    arr[si][sj] = '#';
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj, n, m) && arr[ci][cj] == '.')
        {
            DFS(ci, cj, n, m);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            arr[i].push_back(ch);
        }
    }
    int cnt = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (arr[i][j] == '.')
    //         {
    //             DFS(i, j, n, m);
    //             cnt++;
    //         }
    //     }
    // }
    memset(vis, false, sizeof(vis));
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        pair<int, int> x = q.front();
        q.pop();
        if (arr[x.first][x.second] == '.')
        {
            DFS(x.first, x.second, n, m);
            cnt++;
        }
        for (int i = 0; i < 4; i++)
        {
            int ci = x.first + d[i].first;
            int cj = x.second + d[i].second;

            if (valid(ci, cj, n, m) && vis[ci][cj] == false)
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}