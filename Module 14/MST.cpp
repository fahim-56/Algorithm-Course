#include <bits/stdc++.h>
using namespace std;
class edge
{
public:
    int u, v, w;
    edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(edge a, edge b)
{
    return (a.w < b.w);
}
int par[1005];
int Group_Size[1005];
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
void Union_By_Size(int n1, int n2)
{
    int l1 = DSU_Find(n1);
    int l2 = DSU_Find(n2);
    if (Group_Size[l1] > Group_Size[l2])
    {
        par[l2] = l1;
        Group_Size[l1] += Group_Size[l2];
    }
    else
    {
        par[l1] = l2;
        Group_Size[l2] += Group_Size[l1];
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    DSU_Initialize(n);
    vector<edge> v;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(edge(a, b, c));
    }
    sort(v.begin(), v.end(), cmp);
    int minimum_cost = 0;
    for (edge x : v)
    {
        int l1 = DSU_Find(x.u);
        int l2 = DSU_Find(x.v);
        if (l1 != l2)
        {
            Union_By_Size(l1, l2);
            minimum_cost += x.w;
        }
    }
    cout << minimum_cost << endl;
    return 0;
}