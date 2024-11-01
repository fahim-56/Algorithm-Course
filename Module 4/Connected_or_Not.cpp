#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int arr[n][n];
    memset(arr, 0, sizeof(arr));
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (arr[u][v] == 1)
            cout << "YES" << endl;
        else if (u == v)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}