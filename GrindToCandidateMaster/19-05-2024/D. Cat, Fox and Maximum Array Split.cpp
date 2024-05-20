#include<bits/stdc++.h>
using namespace std;

int query(int l, int r) {
	cout << "? " << l << ' ' << r << endl;
	int x; cin >> x;
	if(x==-1)exit(0);
	return x;
}
void print(int res) {
	cout << "! " << res << endl;
}
void solve() {

	int n, k; cin >> n >> k;

	int mx = 1;
	for(int i=2;i<=n;i++) {
		if(query(1,n*i)==n) mx = i;
	}

	int res = -1;
	for(int i=1; i<=n/k; i++) {
		int cur = mx * i;
		int now = 1, cnt = 0;
		while(now <= n && cnt < k) {
			now = query(now, cur)+1; ++cnt;
		}
		if(cnt==k&&now==n+1) {
			res = cur;
		}
	}

	print(res);
	int x; cin >>x;
}

int main() {
	int T; cin >> T;
	for(;T--;) {
		solve();
	}
}
