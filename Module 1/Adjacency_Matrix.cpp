#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int matrix[n][n];
    memset(matrix, 0, sizeof(matrix)); // initialize as 0
    while (e--)                        //  set the edge at matrix
    {
        int a, b;
        cin >> a >> b;
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    cout << "WHich One do you want to find...?" << endl;
    int a, b;
    cin >> a >> b;
    if (matrix[a][b] == 1)
        cout << "Ase" << endl;
    else
        cout << "Nai" << endl;
    // 6 6
    // 0 1
    // 1 5
    // 0 4
    // 0 3
    // 3 4
    // 2 4
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}