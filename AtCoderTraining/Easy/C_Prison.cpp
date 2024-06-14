#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> pre(n + 10);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        pre[u]++;
        pre[v + 1]--;
    }

    for (int i = 1; i <= n; i++)
        pre[i] += pre[i - 1];

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (pre[i] == m)
            cnt++;
    }
    cout << cnt;
}