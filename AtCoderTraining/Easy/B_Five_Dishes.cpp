#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> A(5);
    for (auto &x : A)
        cin >> x;

    int ans = INT_MAX;
    vector<int> seen(5, 0);
    for (int a = 0; a < 5; a++)
    {
        seen[a] = 1;
        int tot = ((A[a] + 9) / 10) * 10;
        int prev2 = tot;
        for (int b = 0; b < 5; b++)
        {
            if (seen[b])
                continue;
            seen[b] = 1;

            tot = ((tot + A[b] + 9) / 10) * 10;
            int prev3 = tot;
            for (int c = 0; c < 5; c++)
            {
                if (seen[c])
                    continue;
                seen[c] = 1;
                tot = ((tot + A[c] + 9) / 10) * 10;
                // cout << tot << '\n';
                int prev4 = tot;
                for (int d = 0; d < 5; d++)
                {
                    if (seen[d])
                        continue;
                    seen[d] = 1;
                    tot = ((tot + A[d] + 9) / 10) * 10;
                    // cout << tot << '\n';
                    for (int e = 0; e < 5; e++)
                    {
                        if (!seen[e])
                            ans = min(ans, tot + A[e]);
                    }
                    tot = prev4;
                    seen[d] = 0;
                }
                tot = prev3;
                seen[c] = 0;
            }
            seen[b] = 0;
            tot = prev2;
        }
        seen[a] = 0;
    }
    cout << ans;
}