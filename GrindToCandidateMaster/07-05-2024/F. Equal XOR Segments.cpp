#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> b(n+1);
    map<int, vector<int>> id;
    id[0].push_back(0);

    for(int x, i=0; i<n; i++) {
        cin >> x;
        b[i+1] = b[i] ^ x;
        id[b[i+1]].push_back(i+1);
    }

    for(int i=0; i<q; i++) {
        int l, r; cin >> l >> r;
        bool ok = 0;
        if(b[r] == b[l-1]) ok = 1;
        int T = *--lower_bound(begin(id[b[l-1]]), end(id[b[l-1]]), r);
        int S = *lower_bound(begin(id[b[r]]), end(id[b[r]]), l);
        ok |= (S < T);

        cout << (ok ? "YES": "NO") << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for(; T--; ) {
        solve();
    }
}
