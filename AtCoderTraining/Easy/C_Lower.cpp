#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<int> a(n);

    int ans = 0;

    for (auto &x : a)
        cin >> x;

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        while (i + 1 < n && a[i + 1] <= a[i])
            i++, cnt++;
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}