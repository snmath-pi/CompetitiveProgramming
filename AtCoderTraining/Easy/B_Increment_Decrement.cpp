#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        x += (s[i] == 'I' ? 1 : -1);
        ans = max(ans, x);
    }
    cout << ans;
}