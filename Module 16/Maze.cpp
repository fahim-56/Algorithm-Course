#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char mtx[N][N];
bool vis[N][N];
int n, m;
bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
map<pair<int, int>, pair<int, int>> mp;
vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
void BFS(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
    while (!q.empty())
    {
        int si = q.front().first;
        int sj = q.front().second;
        q.pop();
        for (pair<int, int> x : p)
        {
            int ci = si + x.first;
            int cj = sj + x.second;
            if (valid(ci, cj) && !vis[ci][cj] && mtx[ci][cj] != '#')
            {
                q.push({ci, cj});
                mp[{ci, cj}] = {si, sj};
                vis[ci][cj] = true;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int ai, aj, bi, bj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mtx[i][j];
            vis[i][j] = false;
            if (mtx[i][j] == 'R')
            {
                ai = i;
                aj = j;
            }
            if (mtx[i][j] == 'D')
            {
                bi = i;
                bj = j;
            }
        }
    }
    BFS(ai, aj);

    if (!vis[bi][bj])
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << mtx[i][j];
            }
            cout << endl;
        }
        return 0;
    }
    while (bi != ai || bj != aj)
    {
        int ki = bi;
        int kj = bj;
        bi = mp[{ki, kj}].first;
        bj = mp[{ki, kj}].second;
        if (mtx[bi][bj] != 'R')
            mtx[bi][bj] = 'X';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mtx[i][j];
        }
        cout << endl;
    }
    return 0;
}