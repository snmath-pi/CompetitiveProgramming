#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, k; cin >> n >> m >> k;

	vector<vector<int>> g(n);
	for(int i=0; i<m; i++) {
		int u, v; cin >> u >> v; 
		g[--u].push_back(--v);
		g[v].push_back(u);
	}
	vector<bool> seen(n, 0);
	int cnt = 0;
	auto dfs = [&](int i, int p, auto &&dfs)->void {
		cnt++; seen[i] = 1;
		for(auto j: g[i]) {
			if(!seen[j]) dfs(j, i, dfs);
		}
	}; 

	vector<int> comp;
	for(int i=0; i<n; i++) {
		if(!seen[i]) {
			cnt = 0;
			dfs(i, -1, dfs);
			comp.push_back(cnt);
		}
	}
	sort(rbegin(comp), rend(comp));
	int ans = comp[0];
	for(int i=1; i<comp.size() && k; i++) {
		k--; ans += comp[i];
	}
	cout << ans << '\n';
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 1;
	// cin >> T;
	for(; T--; ) {
		solve();
	}
}
