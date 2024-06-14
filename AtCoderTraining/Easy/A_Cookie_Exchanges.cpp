#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c)
    {
        cout << (a % 2 == 0 && b % 2 == 0 && c % 2 == 0 ? -1 : 0);
    }
    else
    {
        int cnt = 0;
        while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0)
        {
            int x = b / 2 + c / 2;
            int y = a / 2 + c / 2;
            int z = a / 2 + b / 2;
            a = x, b = y, c = z;
            cnt++;
        }
        cout << cnt;
    }
}