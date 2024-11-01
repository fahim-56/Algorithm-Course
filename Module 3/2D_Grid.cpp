#include <bits/stdc++.h>
using namespace std;
const int N = 100;
char ar[N][N];
bool visited[N][N] = {false};
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
void DFS(int i, int j)
{
    cout << i << " " << j << endl;
    visited[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int ci = i + v[k].first;
        int cj = j + v[k].second;
        if (valid(ci, cj) && visited[ci][cj] == false)
        {
            DFS(ci, cj);
        }
    }
}
int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ar[i][j] = '.';
        }
    }
    int si, sj;
    cin >> si >> sj;
    DFS(si, sj);
    return 0;
}