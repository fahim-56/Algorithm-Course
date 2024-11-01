#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool valid(int i, int j, int row, int col)
    {
        return (i >= 0 && i < row && j >= 0 && j < col);
    }
    void BFS(vector<vector<int>> &grid, int row, int col)
    {
        queue<pair<int, int>> q;
        bool vis[row][col];
        memset(vis, false, sizeof(vis));
        vector<pair<int, int>> v = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        q.push({0, 0});
        while (!q.empty())
        {
            for (int i = 0; i < 4; i++)
            {
                int cr = q.front().first + v[i].first;
                int cc = q.front().second + v[i].second;
                if ( valid(cr, cc, row, col) && grid[cr][cc] = 0)
                {
                    q.push({cr, cc});
                }
            }
            q.pop();
        }
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < col; i++)
        {
            if (grid[0][i] == 0)
            {
            }
            if (grid[row - 1][i] == 0)
            {
            }
        }
        for (int i = 0; i < row; i++)
        {
            if (grid[i][0] == 0)
            {
            }
            if (grid[i][col - 1] == 0)
            {
            }
        }
    }
};
int main()
{

    return 0;
}