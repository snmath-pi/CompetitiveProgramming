#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < m; i++)
    {
        int v;
        cin >> v;
        cnt1 += (v <= x);
        cnt2 += (v >= x);
    }
    cout << min(cnt1, cnt2);
}