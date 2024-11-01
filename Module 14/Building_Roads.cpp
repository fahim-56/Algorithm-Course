#include <bits/stdc++.h>
using namespace std;
int par[100005];
int Group_Size[100005];
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
    DSU_Initialize(n + 1);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int l1 = DSU_Find(a);
        int l2 = DSU_Find(b);
        if (l1 != l2)
        {
            Union_By_Size(l1, l2);
        }
    }
    vector<int> lv;
    for (int i = 1; i <= n; i++)
    {
        int l = DSU_Find(i);
        lv.push_back(l);
    }
    sort(lv.begin(), lv.end());
    lv.erase(unique(lv.begin(), lv.end()), lv.end());
    cout << lv.size() - 1 << endl;
    for (int i = 0; i < (lv.size() - 1); i++)
    {
        cout << lv[i] << " " << lv[i + 1] << endl;
    }

    return 0;
}