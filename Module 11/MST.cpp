#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int GroupSize[N];
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
    if (GroupSize[leaderA] > GroupSize[leaderB])
    {
        par[leaderB] = leaderA;
        GroupSize[leaderA] += GroupSize[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        GroupSize[leaderB] += GroupSize[leaderA];
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
int main()
{
    int n, e;
    cin >> n >> e;
    DSU_Initialize(n);
    vector<Edge> edgeList;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edgeList.push_back(Edge(a, b, c));
    }
    sort(edgeList.begin(), edgeList.end(), cmp);
    int minimumCost = 0;
    cout << endl;
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
    cout << minimumCost << endl;
    return 0;
}
// 5 7
// 0 1 2
// 0 2 3
// 0 3 3
// 3 4 6
// 2 4 4
// 2 1 7
// 1 4 5
