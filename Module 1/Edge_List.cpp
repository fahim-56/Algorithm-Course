#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> e >> n;
    vector<pair<int, int>> v;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    for (pair<int, int> x : v)
    {
        cout << x.first << " " << x.second << endl;
    }
    //     6 6
    //     0 1
    //     1 5
    //     0 4
    //     0 3
    //     3 4
    //     2 4
    return 0;
}