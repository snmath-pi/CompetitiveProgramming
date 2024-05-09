#include<bits/stdc++.h>
using namespace std;

int query(int l, int r) {
	if(l>=r)return -1;
	cout << "? " << l << ' ' << r << endl;
	int x; cin >> x;
	return x;
}
void print(int res) {
	cout << "! " << res << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	int l = 1, r = n;
	int pos = query(l, r);
	int pos2 = query(l, pos);
	int ok = 0;
	
	if(pos != pos2) {
		ok = 1;
	}

	if(ok) {
		l = pos, r = n + 1;
		while(r > l + 1) {
			int m = l + r >> 1;
			pos2 = query(pos, m);
			if(pos2==pos) r = m;
			else l = m;
		}
		print(r);
	} else {
		l = 1, r = pos;
		while(r > l + 1) {
			int m = l + r >> 1;
			pos2 = query(m, pos);
			if(pos2==pos) l = m;
			else r = m;
		}
		print(l);
	}


}
