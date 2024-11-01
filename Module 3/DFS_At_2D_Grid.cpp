#include <bits/stdc++.h>
using namespace std;
char v[100][100];
bool vis[100][100] = {false};
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
void DFS(int si, int sj)
{
    cout << si << " " << sj << endl;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + p[i].first;
        int cj = sj + p[i].second;
        if (valid(ci, cj) && vis[ci][cj] == false)
        {
            DFS(ci, cj);
        }
    }
}
int main()
{
    cout << "Enter the value of n,m:" << endl;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            v[i][j] = '.';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    int si, sj;
    cout << "Enter Your Source" << endl;
    cin >> si >> sj;
    DFS(si, sj);
    return 0;
}