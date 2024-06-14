#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p(n), q(n);

    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> q[i];

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    int cnt1 = 0, cnt2 = 0;
    if (p == a)
        cnt1 = 1;
    if (q == a)
        cnt2 = 1;
    int cnt = 2;
    do
    {
        if (p == a)
            cnt1 = cnt;
        if (q == a)
            cnt2 = cnt;
        cnt++;
    } while (next_permutation(begin(a), end(a)));
    cout << abs(cnt1 - cnt2);
}