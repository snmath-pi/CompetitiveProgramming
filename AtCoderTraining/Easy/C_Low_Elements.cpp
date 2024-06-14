#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int res = 0;
    int mx;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        if (!i)
        {
            res++;
            mx = v;
            continue;
        }
        if (v <= mx)
            res++;
        mx = min(mx, v);
    }

    cout << res;
}