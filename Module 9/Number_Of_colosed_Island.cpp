#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n, m;
    bool flag;
    bool valid(int i, int j)
    {
        return (i < n && i >= 0 && j < m && j >= 0);
    }
    bool flag;
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void DFS(int i, int j, vector<vector<int>> &grid)
    {
        if (grid[i][j] == 0 || grid[i][j] == n - 1 || grid[j][i] == 0 || grid[j][i] == n - 1)
        {
            flag = false;
        }
        grid[i][j] = 1;
        for (pair<int, int> x : moves)
        {
            int ci = i + x.first;
            int cj = j + x.second;
            if (valid(ci, cj) && grid[ci][cj] == 0)
            {
                DFS(ci, cj, grid);
            }
        }
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    flag = true;
                    DFS(i, j, grid);
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