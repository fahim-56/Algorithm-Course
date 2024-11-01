#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> list[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        for (int x : list[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}