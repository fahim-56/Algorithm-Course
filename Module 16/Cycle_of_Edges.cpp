#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int Group_Size[N];
void DSU_Initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        Group_Size[i] = 1;
    }
}
int DSU_Find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = DSU_Find(par[node]);
    par[node] = leader;
    return leader;
}
void Union_By_Size(int node1, int node2)
{
    int leaderA = DSU_Find(node1);
    int leaderB = DSU_Find(node2);
    if (Group_Size[leaderA] > Group_Size[leaderB])
    {
        par[leaderB] = leaderA;
        Group_Size[leaderA] += Group_Size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        Group_Size[leaderB] += Group_Size[leaderA];
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    DSU_Initialize(n);
    int cnt = 0;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = DSU_Find(a);
        int leaderB = DSU_Find(b);
        if (leaderA == leaderB)
        {
            cnt++;
        }
        else
        {
            Union_By_Size(a, b);
        }
    }
    cout << cnt << endl;
    return 0;
}