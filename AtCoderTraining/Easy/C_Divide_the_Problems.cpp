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

    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(begin(a), end(a));

    if (a[n / 2] == a[n / 2 - 1])
    {
        cout << 0;
    }
    else
    {
        cout << a[n / 2] - a[n / 2 - 1];
    }
}