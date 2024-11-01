#include <bits/stdc++.h>
using namespace std;
int par[1005];
int Group_size[1005];
void DSU_Initilize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        Group_size[i] = 1;
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
void DSU_Union_By_Size(int node1, int node2)
{
    int leaderA = DSU_Find(node1);
    int leaderB = DSU_Find(node2);
    if (Group_size[leaderA] > Group_size[leaderB])
    {
        par[leaderB] = leaderA;
        Group_size[leaderA] += Group_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        Group_size[leaderB] += Group_size[leaderA];
    }
}
int main()
{
    int n;
    cin >> n;
    DSU_Initilize(n);
    DSU_Union_By_Size(1, 0);
    DSU_Union_By_Size(1, 2);
    DSU_Union_By_Size(2, 3);
    DSU_Union_By_Size(3, 4);

    DSU_Union_By_Size(7, 8);
    DSU_Union_By_Size(6, 7);

    // DSU_Union_By_Size(3,6);

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << DSU_Find(i) << " -> " << Group_size[i] << endl;
    }

    return 0;
}