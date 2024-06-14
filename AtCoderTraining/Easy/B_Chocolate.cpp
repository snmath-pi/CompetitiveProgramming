#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d, x;
    cin >> n >> d >> x;

    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        x += ((d - 1) / v + 1);
    }
    cout << x;
}