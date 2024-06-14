#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;

    unordered_set us(begin(s), end(s));
    cout << (us.size() == s.size() ? "yes" : "no");
}