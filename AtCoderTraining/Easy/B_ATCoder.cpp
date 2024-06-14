#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<char> s{'A', 'C', 'G', 'T'};

    string t;
    cin >> t;

    int ans = 0;
    int n = t.size();
    for (int i = 0; i < n; i++)
    {

        if (s.count(t[i]))
        {
            int cnt = 0;

            while (i < n && s.count(t[i]))
                i++, cnt++;
            ans = max(ans, cnt);
            i--;
        }
    }
    cout << ans;
}