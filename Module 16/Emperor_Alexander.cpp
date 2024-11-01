#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N = 1e5 + 5;
ll par[N];
ll GroupSize[N];
void DSU_Initialize(ll n)
{
    for (ll i = 1; i <= n; i++)
    {
        par[i] = -1;
        GroupSize[i] = 1;
    }
}
ll DSU_Find(ll node)
{
    if (par[node] == -1)
        return node;
    ll leader = DSU_Find(par[node]);
    par[node] = leader;
    return leader;
}
void DSU_Union_By_Size(ll node1, ll node2)
{
    ll leaderA = DSU_Find(node1);
    ll leaderB = DSU_Find(node2);
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
    ll u, v, w;
    Edge(ll u, ll v, ll w)
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
    ll n, e;
    cin >> n >> e;
    DSU_Initialize(n);
    vector<Edge> edgeList;
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edgeList.push_back(Edge(a, b, c));
    }
    sort(edgeList.begin(), edgeList.end(), cmp);
    ll minimumCost = 0;

    int cnt = 0;
    int l = 0;
    for (Edge ed : edgeList)
    {
        ll l1 = DSU_Find(ed.u);
        ll l2 = DSU_Find(ed.v);

        if (l1 != l2)
        {
            DSU_Union_By_Size(l1, l2);
            minimumCost += ed.w;
            l++;
        }
        else
        {
            cnt++;
        }
    }
    if (l != n - 1)
    {
        cout << "Not Possible" << endl;
        return 0;
    }
    cout << cnt << " ";
    cout << minimumCost << endl;
    return 0;
}
