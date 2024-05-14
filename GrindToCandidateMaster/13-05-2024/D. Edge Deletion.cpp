int main() {
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    
    cin >> n >> m >> k;
 
    vector<vector<pair<int, pii>>> g(n);
    rep(i, m) {
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        g[u].pb({v, {w, i}});
        g[v].pb({u, {w, i}});
    }
 
    vl dis(n, 1e18); vi vis(n, -1);
    dis[0] = 0;
    set<pll> pq;
    pq.insert({0, 0});
    int left = 0;
    tsi s;
    while(!pq.empty() && left < k) {
        auto x = *pq.begin(); pq.erase(pq.begin());
        
        if(vis[x.se] != -1) {
            s.insert(vis[x.se]);
            left++;
        }
        for(auto [y, w]: g[x.se]) {
            if(dis[y] > dis[x.se] + w.fi) {
                pq.erase({dis[y], y});
                dis[y] = dis[x.se] + w.fi;
                pq.insert({dis[y], y});           
                vis[y] = w.se+1;
            }
        }
    }
 
    cout << sz(s) << nl;
    printset(s);
 
 
}
