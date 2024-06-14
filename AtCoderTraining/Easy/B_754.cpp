#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ans = INT_MAX;

    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n - 2; i++)
    {
        int val = stoi(s.substr(i, 3));
        ans = min(ans, abs(val - 753));
    }
    cout << ans;
}