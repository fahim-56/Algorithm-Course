#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int group_size[N];
void dsu_initialize(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}
int dsu_find(int node)
{
    if (parent[node] == -1)
        return node;
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}
void union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
int main()
{
    int n;
    cin >> n;
    dsu_initialize(n);
    vector<pair<int, int>> closed;
    vector<pair<int, int>> build;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        int l1 = dsu_find(a);
        int l2 = dsu_find(b);
        if (l1 == l2)
        {
            closed.push_back({a, b});
        }
        else
        {
            union_by_size(a, b);
        }
    }
    for (int i = 2; i <= n; i++)
    {
        int l1 = dsu_find(1);
        int l2 = dsu_find(i);
        if (l1 != l2)
        {
            build.push_back({1, i});
            union_by_size(l1, i);
        }
    }
    // cout << closed[0].first << " " << closed[0].second;
    cout << closed.size() << endl;
    for (int i = 0; i < closed.size(); i++)
    {
        cout << closed[i].first << " " << closed[i].second << " " << build[i].first << " " << build[i].second << endl;
    }

    return 0;
}