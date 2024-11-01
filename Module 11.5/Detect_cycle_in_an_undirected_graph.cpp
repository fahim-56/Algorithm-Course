#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int par[100005];
    int Group_Size[100005];
    bool vis[100005];
    void DSU_Initialize(int n)
    {
        for (int i = 0; i < n; i++)
        {
            par[i] = -1;
            Group_Size[i] = 1;
            vis[i] = false;
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

    bool isCycle(int V, vector<int> adj[])
    {
        DSU_Initialize(V);
        bool cycle = false;
        for (int i = 0; i < V; i++)
        {
            for (int x : adj[i])
            {
                if (!vis[x])
                {
                    int leaderA = DSU_Find(i);
                    int leaderB = DSU_Find(x);
                    if (leaderA == leaderB)
                    {
                        cycle = true;
                    }
                    else
                    {
                        DSU_Union_By_Size(leaderA, leaderB);
                    }
                }
            }
            vis[i] = true;
        }
        return cycle;
    }
};
int main()
{

    return 0;
}