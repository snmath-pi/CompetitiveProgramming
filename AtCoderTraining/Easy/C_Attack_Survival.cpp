#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n + 1, k - q);

    for (int i = 0; i < q; i++)
    {
        int v;
        cin >> v;
        a[v]++;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << (a[i] > 0 ? "Yes" : "No") << '\n';
    }
}