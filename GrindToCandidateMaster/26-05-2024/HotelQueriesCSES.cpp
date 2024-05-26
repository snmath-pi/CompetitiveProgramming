#include<bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 10;
int t[4*N], a[N];
 
void build(int x, int tl, int tr) {
    if(tl == tr) {
        t[x] = a[tl];
    } else {
        int tm = tl + tr >> 1;
        build(2*x, tl, tm); build(2*x+1, tm+1, tr);
        t[x] = max(t[2*x], t[2*x+1]);
    }
}
 
int find(int x, int tl, int tr, int val) {
    if(val > t[x]) return -1;
    if (tl == tr) return tl;
 
    int tm = (tl+tr)/2;
    if(t[2*x] >= val) {
        return find(2*x, tl, tm, val);
    } else {
        return find(2*x+1, tm+1, tr, val);
    }
}
void update(int v, int tl, int tr, int pos, int val) {
    if(tl == tr) {
        t[v] = val;
    } else {
        int tm = (tl+tr)/2;
        if(pos <= tm) {
            update(2*v, tl, tm, pos, val);
        } else {
            update(2*v+1, tm+1, tr, pos, val);
        }
        t[v] = max(t[2*v], t[2*v+1]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
 
    for(int i=0; i<n; i++) cin >> a[i];
 
    build(1, 0, n-1);
    for(int i=0; i<m; i++) {
        int x; cin >> x;
        int j = find(1, 0, n-1, x);
        if(j==-1) {
            cout << 0 << ' ';
        } else {
            a[j] -= x;
            update(1, 0, n-1, j, a[j]);
            cout << j + 1 << ' ';
        }
    }
}
