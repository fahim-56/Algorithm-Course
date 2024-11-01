// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
// int n;
// cin >> n;
// int mtx[n][n];
// for (int i = 0; i < n; i++)
// {
//     for (int j = 0; j < n; j++)
//     {
//         cin >> mtx[i][j];
//     }
// }

//     vector<int> adj[n];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (mtx[i][j] == 1)
//             {
//                 adj[i].push_back(j);
//             }
//         }
//     }
//     return 0;
// }
// 3
// 0 1 0
// 1 0 1
// 1 1 0
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int mtx[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mtx[i][j];
        }
    }
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mtx[i][j] > 0)
            {
                adj[i].push_back({j, mtx[i][j]});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << "->";
        for (pair<int, int> x : adj[i])
        {
            cout << "{" << x.first << "," << x.second << "},";
        }
        cout << endl;
    }

    return 0;
}
// 4
// 0 5 -1 -1
// -1 0 6 -1
// -1 -1 0 7
// -1 8 7 0