#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, m;
    cin >> a >> b >> m;
    vector<int> A(a), B(b);

    for (int i = 0; i < a; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < b; i++)
    {
        cin >> B[i];
    }
    int ans = *min_element(begin(A), end(A)) + *min_element(begin(B), end(B));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        int ci;
        cin >> ci;
        --u, --v;
        ans = min(ans, max(0, A[u] + B[v] - ci));
    }
    cout << ans;
}