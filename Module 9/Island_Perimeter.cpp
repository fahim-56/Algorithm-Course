#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> grid(105);

int l, k;
int ans = 0;
bool valid(int i, int j)
{
    return (i < k && i >= 0 && j < l && j >= 0);
}
bool vis[105][105];
vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void DFS(int si, int sj)
{
    vis[si][sj] = true;
    for (pair<int, int> x : d)
    {
        int ci = si + x.first;
        int cj = sj + x.second;
        if (valid(ci, cj))
        {
            if (grid[ci][cj] == 0)
                ans++;
        }
        else
        {
            ans++;
        }
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1)
        {
            DFS(ci, cj);
        }
    }
}
int islandPerimeter(vector<vector<int>> &grid)
{
    memset(vis, false, sizeof(vis));
    k = grid.size();
    l = grid[0].size();
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (grid[i][j] == 1)
            {
                DFS(i, j);
            }
        }
    }
    return ans;
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            grid[i].push_back(x);
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << islandPerimeter(grid) << endl;

    return 0;
}