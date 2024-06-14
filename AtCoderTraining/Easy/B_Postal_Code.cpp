#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int ok = (s[a] == '-');
    for (int i = 0; i < s.size(); i++)
    {
        if (i == a)
            continue;
        ok &= (s[i] >= '0' && s[i] <= '9');
    }
    cout << (ok ? "Yes" : "No");
}