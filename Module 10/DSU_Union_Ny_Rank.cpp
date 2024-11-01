#include <bits/stdc++.h>
using namespace std;
int par[1005];
int level[1005];
void DSU_Initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        level[i] = 0;
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
void DSU_Union_By_Rank(int node1, int node2)
{
    int leaderA=DSU_Find(node1);
    int leaderB=DSU_Find(node2);
    if (level[leaderA] > level[leaderB])
    {
        par[leaderB] = leaderA;
    }
    else if (level[leaderB] > level[leaderA])
    {
        par[leaderA] = leaderB;
    }
    else
    {
        par[leaderA] = leaderB;
        level[leaderB]++;
    }
}
int main()
{
    int n;
    cin >> n;
    DSU_Initialize(n);
    DSU_Union_By_Rank(0, 1);
    DSU_Union_By_Rank(1, 2);
    DSU_Union_By_Rank(3, 2);
    DSU_Union_By_Rank(4, 3);

    DSU_Union_By_Rank(7, 8);
    DSU_Union_By_Rank(6, 7);

    DSU_Union_By_Rank(3, 7);

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << DSU_Find(i) << " -> " << level[i] << endl;
    }

    return 0;
}