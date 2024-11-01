#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
void Initilize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
    }
    parent[1] = 0;
    parent[2] = 1;
    parent[3] = 2;
    parent[4] = 3;
}
int Find(int node)
{
    if (parent[node] == -1)
        return node;
    int leader = Find(parent[node]);
    parent[node] = leader;
    return leader;
}
int main()
{
    int n;
    cin >> n;
    Initilize(n);
    Find(4);
    for (int i = 0; i < n; i++)
    {
        cout << parent[i] << endl;
    }

    return 0;
}