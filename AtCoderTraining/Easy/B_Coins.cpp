#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, x;
    cin >> a >> b >> c >> x;

    int res = 0;
    set<int> s;
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            int val = x - i * 500 - j * 100;
            if (val >= 0 && val % 50 == 0 && val / 50 <= c)
            {
                res++;
            }
        }
    }

    cout << res;
}