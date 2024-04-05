#include <bits/stdc++.h>
using namespace std;
const int LG = 19;
const int N = 2e5 + 100;
int in[N], out[N];
int main() {
	int n, q; cin >> n >> q;
	vector<vector<int>> g(n);

	for(int i=0; i<n-1; i++) {
		int u, v; cin >> u >> v; --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	int time = 0;
	auto dfs = [&](int i, int p, auto &&dfs)->void {
		in[i] = time++;
		for(auto j: g[i]) {
			if(j == p) continue;
			dfs(j, i, dfs);
		}
		out[i] = time++;
	}; dfs(0, -1, dfs);
	
	while(q--) {
		int x, y; cin >> x >> y; --x, --y;
		cout << (in[x] < in[y] && out[x] > out[y] ? "YES" : "NO") << '\n';
	}
}
