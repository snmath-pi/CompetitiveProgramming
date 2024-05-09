#include<bits/stdc++.h>
using namespace std;

int query(int l, int r) {
	cout << "? " << l << ' ' << r << endl;
	int x; cin >> x;
	return x;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	int l = 1, r = n;
	int pos = query(l, r);
	while(r-l>1) {
		int pos2, m = l + r >> 1;
		if(pos == m) {
			if(m==r) {
				cout << "! " << r << endl; return 0;
			}
			pos2 = query(m, r);
			if(m==l) {
				cout << "! " << l << endl; return 0;
			}
			if(pos2 == pos) {
				l = m;
			} else {
				r = m;
			}
			continue;
		}
		if(pos>m) {
			if(m==r) {
				cout << "! " << m << endl; return 0;
			}
			pos2 = query(m, r);

			if(pos2 != pos) {
				r = m-1;
				if(l==m-1) {
					cout << "! " << m-1 << endl; return 0;
				}
				pos = query(l, m-1);
			} else {
				l = m;
			}
		} else {
			if(l==m) {
				cout << "! " << m << endl; return 0;
			}
			pos2 = query(l, m);
			if(pos2 != pos) {
				if(m+1==r) {
					cout << "! " << r << endl; return 0;
				}
				l = m+1; pos = query(m+1, r);
			} else {
				r = m;
			}
		}
	}

	cout << "! " << (pos == l ? r : l) << endl;

}
