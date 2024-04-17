#include<bits/stdc++.h>
using namespace std;

const int M=998244353;
int add(int x, int y) {
	x += y;
	return x >= M ? x - M : x;
}
int mult(int x, int y) {
	return x*1ll*y%M;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N; cin >> N;
	vector<int> A(N);
	int S = 0;
	for(int i=0; i<N; i++) {
		cin >> A[i]; S+=A[i];
	}
	int dp[S+1]={};
	dp[0]=1;
	for(int i=0;i<N;i++) for(int j=S-A[i];j>=0;j--) dp[j+A[i]]=add(dp[j+A[i]],dp[j]);
	
	int res = 0;
	for(int j=0;j<=S;j++)res=add(res,mult((j+1)/2,dp[j]));
	for(int i=0;i<N;i++)for(int j=0;j<A[i];j++)res=add(res,mult(A[i]-(j+A[i]+1)/2,dp[j]));
	cout << res << '\n';
		
}
