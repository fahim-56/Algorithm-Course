#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> adj[200005];
    bool vis[200005];
    void DFS(int src)
    {
        vis[src] = true;
        for (int child : adj[src])
        {
            if (!vis[child])
            {
                DFS(child);
            }
        }
    }
    bool validPath(int n, vector<vector<int>> &edges, int s, int d)
    {
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        DFS(s);
        return vis[d];
    }
};

class Solution
{
public:
    int n, m;
    bool valid(int i, int j)
    {
        return (i < n && i >= 0 && j < m && j >= 0);
    }
    int cnt;
    vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void DFS(vector<vector<int>> &grid, int i, int j)
    {
        cnt++;
        grid[i][j] = 0;
        for (pair<int, int> x : d)
        {
            int ci = i + x.first;
            int cj = j + x.second;
            if (valid(ci, cj) && grid[ci][cj] == 1)
            {
                DFS(grid, ci, cj);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    cnt = 0;
                    DFS(grid, i, j);
                    mx = max(mx, cnt);
                }
            }
        }
    }
};
class Solution
{
public:
    int n, m;
    bool valid(int i, int j)
    {
        return (i < n && i >= 0 && j < m && j >= 0);
    }
    vector<pair<int, int>> d = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void DFS(int i, int j, vector<vector<char>> &grid)
    {
        grid[i][j] = 0;
        for (pair<int, int> x : d)
        {
            int ci = i + x.first;
            int cj = j + x.second;
            if (valid(ci, cj) && grid[ci][cj] == 1)
            {
                DFS(ci, cj, grid);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    cnt++;
                    DFS(i, j, grid);
                }
            }
        }
        return cnt;
    }
};

int main()
{
    return 0;
}