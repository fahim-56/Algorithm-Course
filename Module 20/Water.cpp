#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i] << " ";
        // }

        int f = arr[0], l1 = 0;
        int s = arr[1], l2 = 1;
        if (f < s)
        {
            swap(f, s);
            swap(l1, l2);
        }
        for (int i = 2; i < n; i++)
        {
            if (f < arr[i])
            {
                s = f;
                f = arr[i];
                l2 = l1;
                l1 = i;
            }
            else if (s < arr[i])
            {
                s = arr[i];
                l2 = i;
            }
        }
        if (l1 < l2)
            cout << l1 << " " << l2 << endl;
        else
            cout << l2 << " " << l1 << endl;
    }

    return 0;
}