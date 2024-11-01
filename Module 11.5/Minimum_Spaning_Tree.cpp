#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int par[1005];
    int GroupSize[1005];
    void DSU_Initialize(int n)
    {
        for (int i = 0; i < n; i++)
        {
            par[i] = -1;
            GroupSize[i] = 1;
        }
    }
    int DSU_Find(int node)
    {
        if (par[node == -1])
            return node;
        int leader = DSU_Find(par[node]);
        par[node] = leader;
        return leader;
    }
    void DSU_Union_By_Size(int n1, int n2)
    {
        int l1 = DSU_Find(n1);
        int l2 = DSU_Find(n2);
        if (l1 > l2)
        {
            par[l2] = l1;
            GroupSize[l1] += GroupSize[l2];
        }
        else
        {
            par[l1] = l2;
            GroupSize[l2] += GroupSize[l1];
        }
    }
    class Edge
    {
    public:
        int u, v, w;
        Edge(int u, int v, int w)
        {
            this->u = u;
            this->v = v;
            this->w = w;
        }
    };
    bool cmp(Edge a, Edge b)
    {
        return (a.w < b.w);
    }
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        DSU_Initialize(V);
        vector<Edge> edgeList;
        for (int i = 0; i < V; i++)
        {
            for (vector<int> x : adj[i])
            {
                edgeList.push_back(Edge(i, x[0], x[1]));
            }
        }
        sort(edgeList.begin(), edgeList.end(), cmp);
        int minimumCost = 0;
        for (Edge ed : edgeList)
        {
            int l1 = DSU_Find(ed.u);
            int l2 = DSU_Find(ed.v);
            if (l1 != l2)
            {
                DSU_Union_By_Size(l1, l2);
                minimumCost += ed.w;
            }
        }
        return minimumCost;
    }
};
int main()
{

    return 0;
}