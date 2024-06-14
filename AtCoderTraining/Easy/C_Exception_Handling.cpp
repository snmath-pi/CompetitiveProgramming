#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int mx = 0;
    int smx = 0;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] >= mx)
        {
            smx = mx;
            mx = a[i];
        }
        else
        {
            smx = max(smx, a[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] != mx)
        {
            cout << mx << '\n';
        }
        else
        {
            cout << smx << '\n';
        }
    }
}