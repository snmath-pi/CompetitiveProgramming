#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int mx = 0;
    for (int i = 0; i < n - 1; i++)
    {
        mx = max(mx, a[i + 1] - a[i]);
    }
    mx = max(mx, k - a[n - 1] + a[0]);
    cout << k - mx << '\n';
}