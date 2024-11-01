#include <bits/stdc++.h>
using namespace std;
int n;
char mtx[50][50];
bool vis[50][50];
int dis[50][50];

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < n);
}

vector<pair<int, int> > moves;
void BFS(int i, int j)
{
    queue<pair<int, int> > q;
    q.push({i, j});
    dis[i][j]=0;
    while (!q.empty())
    {
        int si = q.front().first;
        int sj = q.front().second;
        vis[si][sj] = true;
        q.pop();
        for (int i=0;i<4;i++)
        {
            int ci = si +moves[i].first;
            int cj = sj + moves[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && mtx[ci][cj] != 'T')
            {
                q.push({ci, cj});
                dis[ci][cj] = dis[si][sj] + 1;
            }
        }
    }
}

int main()
{
    moves.push_back({0, 1});
    moves.push_back({-1, 0});
    moves.push_back({0, -1});
    moves.push_back({1, 0});
    while (cin >> n)
    {
        int ai, aj, bi, bj;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mtx[i][j];
                if (mtx[i][j] == 'S')
                {
                    ai = i;
                    aj = j;
                }
                if (mtx[i][j] == 'E')
                {
                    bi = i;
                    bj = j;
                }
            }
        }
        memset(vis,false,sizeof(vis));
        memset(dis,-1,sizeof(dis));
        BFS(ai, aj);
        cout << dis[bi][bj] << endl;
    }
    return 0;
}