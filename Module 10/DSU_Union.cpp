#include <bits/stdc++.h>
using namespace std;
int n;
int par[1005];
void DSU_Initilize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
    }
    par[4] = 3;
    par[3] = 2;
    par[2] = 1;
    par[1] = 0;
    par[6] = 7;
    par[7] = 8;
}
int DSU_Find_Parent(int node)
{
    if (par[node] == -1) // parrent e pousai gele parent kei ferot
        return node;
    int leader = DSU_Find_Parent(par[node]); // par jao node er leader khuje ano
    par[node] = leader;
    return leader;
}
void DSU_Union_Random(int A, int B)
{
    int leaderA = DSU_Find_Parent(A);
    int leaderB = DSU_Find_Parent(B);
    par[leaderA] = leaderB;
}
int main()
{
    cin >> n;
    DSU_Initilize(n);
    DSU_Find_Parent(4);
    DSU_Find_Parent(6);

    DSU_Union_Random(4, 6);
    for (int i = 0; i < n; i++)
    {
        cout << i << "->" << DSU_Find_Parent(i) << endl;
    }

    return 0;
}