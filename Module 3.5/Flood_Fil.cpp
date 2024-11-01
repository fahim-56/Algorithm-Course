#include <bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int row, int col)
{
    if (i < 0 && i >= row && j < 0 && j >= col)
        return false;
    return true;
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int row = image.size();
    int col = image[0].size();
    bool vis[row][col];
    memset(vis, false, sizeof(vis));
    queue<pair<int, int>> q;
    vector<pair<int, int>> v = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    q.push({sr, sc});
    vis[sr][sc] = true;
    int val = image[sr][sc];
    while (!q.empty())
    {
        image[q.front().first][q.front().second] = color;
        for (int i = 0; i < 4; i++)
        {
            int cr = q.front().first + v[i].first;
            int cc = q.front().second + v[i].second;
            if (valid(cr, cc, row, col) && vis[cr][cc] == false && image[cr][cc] == val)
            {
                q.push({cr, cc});
                vis[cr][cc] = true;
            }
        }
        q.pop();
    }
    return image;
}

int main()
{

    return 0;
}