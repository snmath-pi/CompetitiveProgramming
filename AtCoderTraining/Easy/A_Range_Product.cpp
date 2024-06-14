#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    if (a <= 0 && b >= 0)
    {
        cout << "Zero";
    }
    else if (a > 0)
    {
        cout << "Positive";
    }
    else
    {
        b = min(0, b);
        int tot = abs(b - a) + 1;
        cout << (tot % 2 ? "Negative" : "Positive");
    }
}