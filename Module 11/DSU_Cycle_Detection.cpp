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
    bool cycle = false;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = DSU_Find(a);
        int leaderB = DSU_Find(b);
        if (leaderA == leaderB)
        {
            cycle = true;
        }
        else
        {
            Union_By_Size(a, b);
        }
    }
    if (cycle)
        cout << "Cycle Found" << endl;
    else
        cout << "Cycle Not Found" << endl;
    return 0;
}
// 6 6
// 0 1
// 0 2
// 0 3
// 3 4
// 3 5
// 4 5