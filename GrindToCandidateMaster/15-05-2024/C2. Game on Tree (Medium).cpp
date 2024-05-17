#include<bits/stdc++.h>
using namespace std;


const int M = 3e5 + 10;
vector<long long> a(M);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T = 1; 
	//cin >> T;
	for(;T--;) {
		int N, Q;
		cin >> N >> Q;

		vector<vector<int>> G(N);
		for(int i=0; i<N-1; i++) {
			int u, v; cin >> u >> v;
			G[--u].push_back(--v);
			G[v].push_back(u);
		}
		
		vector<int> DP(N);
		auto dfs = [&](int from, int p, auto &&dfs) -> void {
			
			for(auto to: G[from]) {
				if(to != p) {
					dfs(to, from, dfs);
					DP[from] |= (!DP[to]);
				}
			}
		}; 
		int SRC; cin >> SRC;
		dfs(--SRC, -1, dfs);
		cout << (DP[SRC] ? "Ron" : "Hermione") << '\n';


	}
}
