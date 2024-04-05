#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long
const int N = 1e5 + 10;
ll f[N + 10], iv[N + 10];
ll sum[N + 10], par[N+10], a[N+10];
ll qpow(ll x, ll y) {
	ll res = 1;
	for(; y; y >>= 1) {
		if(y & 1) res = res * x % mod;
		x = x * x % mod;
	}
	return res;
}

void calc() {
	f[0] = 1;
	for(int i=1; i<N; i++) f[i] = f[i-1] * i % mod;
	iv[N-1] = qpow(f[N-1], mod-2);
	for(int i=N-2; i>=0; i--) iv[i] = iv[i + 1] * (i + 1) % mod;
}
ll C(ll x, ll y) {
	if(y > x) return 0;
	return f[x] * iv[x-y] % mod * iv[y] % mod;
}
void dfs(int i, int p, vector<vector<int>> &g) {
	sum[i] = a[i];
	for(auto j: g[i]) {
		if(j == p) continue;
		par[j] = i;
		dfs(j, i, g);
		sum[i] += sum[j];
	}
}
void solve() {
	int n, x; cin >> n >> x;
	vector<vector<int>> g(n);
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n-1; i++) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(par, -1, sizeof(par));
	memset(sum, 0, sizeof(sum));
	
	dfs(0, -1, g);
	if(sum[0] % x) {
		for(int i=0; i<n; i++) {
			cout << 0 << ' ';
		}
		cout << '\n';
		return;
	}
	
	ll y = 0;
	for(int i=0; i<n; i++) {
		if(par[i] != -1 && sum[i] % x == 0) y++;
	}
	
	for(int i=0; i<n; i++) {
		cout << C(y, i) << ' ';
	}
	cout << '\n';

	

}
int main() {
	int T = 1; 
	cin >> T; 
	calc();
	for(; T--; ) {
		solve();
	}
}
