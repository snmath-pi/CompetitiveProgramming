#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(; T--; ) {
		int N; cin >> N;
		vector<int> A(N);
		for(int i=0; i<N; i++) {
			cin >> A[i];
		}
		if(A[0] != A[N-1]) {
			cout << 0 << '\n';
			continue;
		}
		vector<pair<int, int>> X;

		for(int i=0; i<N; i++) {
			if(A[i] == A[0]) {
				int cnt = 0;
				for(; i < N && A[i] == A[0]; i++, cnt++) {}
				X.push_back({i, cnt});
				i--;
			}
		}
		bool ok = X.size() > 1;
		int res = 1e9;
		for(int i=0; i < X.size(); i++) {
			if(i + 1 < X.size() && X[i+1].first - X[i].first - X[i+1].second + 1 > 2) ok = 0;
			res = min(res, X[i].second);
		}

		cout << (ok ? res : -1) << '\n';
	}	
}
