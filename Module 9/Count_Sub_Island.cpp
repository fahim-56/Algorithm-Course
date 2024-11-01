#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n, m;
    bool flag = true;
    bool valid(int i, int j)
    {
        return (i < n && i >= 0 && j < m && j >= 0);
    }
    bool vis[505][505];
    vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void DFS(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        vis[i][j] = true;
        if (grid1[i][j] == 0)
        {
            flag = false;
        }
        grid2[i][j] = 0;
        for (pair<int, int> x : d)
        {
            int ci = i + x.first;
            int cj = j + x.second;
            if (valid(ci, cj) && !vis[ci][cj] && grid2[ci][cj] == 1)
            {
                DFS(ci, cj, grid1, grid2);
            }
        }
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        memset(vis, false, sizeof(vis));
        n = grid2.size();
        m = grid2[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (grid2[i][j] == 1 && !vis[i][j])
                {
                    flag = true;
                    DFS(i, j, grid1, grid2);
                    if (flag)
                    {
                        cnt++;
                    }
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