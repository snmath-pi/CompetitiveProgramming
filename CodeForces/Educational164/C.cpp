#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(; T--; ) {
		string X, Y;
		cin >> X >> Y;
		bool ok = 0;
		for(int i=0; i<(int)X.size(); i++) {
			if(!ok) {
				if(X[i]>Y[i])ok=1;
				else if(X[i]<Y[i]) {swap(X[i],Y[i]);ok=1;}
			} else {
				if(X[i]>Y[i])swap(X[i],Y[i]);
			}
		}
		cout << X << '\n' << Y << "\n";
	}	
}
