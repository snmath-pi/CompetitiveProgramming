void solve() {
    cin >> n >> k;
    vl a = R(n);
    ll tot = (k+1)*(k+2)/2;
    ll x1 = 0, odd = 0, even = 0, x2 = 0;
    rep(i, n) x1 += a[i] / 2, odd += (a[i]%2),even+=(a[i]%2==0),x2 += (k-a[i]+1);

    cout << tot - x1 - x2 - n + odd * (odd+1)/2 + even*(even+1)/2 << nl;
}
