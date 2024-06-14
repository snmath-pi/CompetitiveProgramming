#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = c - a, y = d - b;

    cout << c - y << ' ' << d + x << ' ' << a - y << ' ' << b + x;
}