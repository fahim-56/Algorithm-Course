#include <bits/stdc++.h>
using namespace std;
vector<char> arr[1005];
vector<pair<int, int>> p = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool valid(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
int cnt = 0;
void DFS(int si, int sj, int n, int m)
{
    arr[si][sj] = '#';
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + p[i].first;
        int cj = sj + p[i].second;
        if (valid(ci, cj, n, m) && arr[ci][cj] == '.')
        {
            DFS(ci, cj, n, m);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            arr[i].push_back(ch);
        }
    }
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '.')
            {
                DFS(i, j, n, m);
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }
    if (v.empty())
    {
        cout << 0;
        return 0;
    }
    sort(v.begin(), v.end());
    for (int x : v)
    {
        cout << x << " ";
    }
    return 0;
}