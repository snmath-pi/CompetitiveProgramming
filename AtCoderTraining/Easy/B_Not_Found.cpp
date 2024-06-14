#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    vector<int> f(26);
    for (auto x : s)
        f[x - 'a']++;

    for (int i = 0; i < 26; i++)
    {
        if (f[i] == 0)
        {
            cout << char(i + 'a');
            exit(0);
        }
    }
    cout << "None";
}