#include <bits/stdc++.h>
using namespace std;
int n, m;
bool valid(int i, int j)
{
    return (i < n && i >= 0 && j < m && j >= 0);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int grid[n][m];
        int l = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                grid[i][j] = l;
                l += 1;
            }
        }
        int ki, kj;
        cin >> ki >> kj;
        int qi, qj;
        cin >> qi >> qj;
        // grid[qi][qj] = '*';
        vector<pair<int, int>> v = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
        queue<pair<int, int>> q;
        bool vis[n][m];
        memset(vis, false, sizeof(vis));
        int par[n * m];
        memset(par, -1, sizeof(par));
        q.push({ki, kj});
        vis[ki][kj] = true;
        bool flag = false;

        while (!q.empty())
        {
            for (pair<int, int> x : v)
            {
                if (grid[q.front().first][q.front().second] == grid[qi][qj])
                {
                    flag = true;
                }
                int Ci = q.front().first + x.first;
                int Cj = q.front().second + x.second;
                if (valid(Ci, Cj) && !vis[Ci][Cj])
                {
                    q.push({Ci, Cj});
                    vis[Ci][Cj] = true;
                    par[grid[Ci][Cj]] = grid[q.front().first][q.front().second];
                }
            }
            q.pop();
        }

        if (flag)
        {
            int cnt = 0;
            int s = grid[qi][qj];
            while (s != grid[ki][kj])
            {
                cnt++;
                s = par[s];
            }
            cout << cnt << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}