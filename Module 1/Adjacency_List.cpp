#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> matrix[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    // 6 6
    // 0 1
    // 1 5
    // 0 4
    // 0 3
    // 3 4
    // 2 4
    for (int i = 0; i < n; i++)
    {
        cout << i << "->";
        for (int x : matrix[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}