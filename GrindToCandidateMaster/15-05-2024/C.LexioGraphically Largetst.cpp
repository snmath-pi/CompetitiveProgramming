#include<bits/stdc++.h>
using namespace std;

const int M = 3e5 + 10;
vector<int> a(M);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; cin >> T;
	for(;T--;) {
		int N; cin >> N;
		map<int, set<int>, greater<int>> mp;
		for(int i=1; i<=N; i++) {
			cin >> a[i];

			mp[a[i]+i].insert(i);
		}
		
		set<int, greater<int>> S;
		int iter = 2;
		while(!mp.empty()) {
			int V = mp.begin()->first;
			if(mp[V].empty()) mp.erase(V);
			else {
				S.insert(V);
				mp[V].erase(mp[V].begin());
				if(mp[V-1].size() < mp[V].size()) swap(mp[V-1], mp[V]);
				for(auto x: mp[V]) mp[V-1].insert(x);
				mp.erase(V);
			}
		}	

		for(auto res: S) {
			cout << res << ' ';
		}

		cout << '\n';
	}
}
