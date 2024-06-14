#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(begin(a), end(a));

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (x >= a[i])
        {
            if (i != n - 1)
            {
                x -= a[i];
                cnt++;
            }
            else
            {
                if (x != a[i])
                    break;
                else
                    cnt++;
            }
        }
        else
            break;
    }

    cout << cnt;
}