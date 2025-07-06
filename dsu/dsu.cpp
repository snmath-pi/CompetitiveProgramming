class DSU {
private:
    vector<int> pr, sz;
    int n;
    int comp;
public:
    DSU(int m): n(m) {
        pr.resize(n), sz.resize(n);
        for(int i = 0; i < n; i++) pr[i] = i, sz[i] = 1;
        comp = m;
    }
    int get(int x) {
        return (x == pr[x] ? x : get(pr[x]));
    }
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) {
            return false;
        }
        if (sz[x] < sz[y]) swap(x, y);
        pr[y] = x;
        sz[x] += sz[y];
        sz[y] = 0;
        comp--;
        return true;
    }
    int gpr(int id) {
        return pr[id];
    }
    int szr(int id) {
        return sz[id];
    }
    int getComp() {
        return comp;
    }
    void reset() {
        for (int i = 0; i < n; i++) pr[i] = i, sz[i] = 1;
        comp = n;
    }
};
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        vector<vector<pair<int, int>>> g(n);
        int mx = 0;
        for (auto& x: edges) {
            mx = max(mx, x[2]);
        }
        DSU d(n);
        auto chk = [&](int time) {
            d.reset();
            // cout << time << '#';
            for(auto& x: edges) {
                if (x[2] > time) {
                    d.unite(x[0], x[1]);
                }
            }

            // cout << d.getComp() << '\n';

            return d.getComp() >= k;
        };

        int l = -1, r = mx + 10;
        while (r > l + 1) {
            int m = (l + r) / 2;
            if (chk(m)) {
                r = m;
            } else {
                l = m;
            }
        }

        return r;
    }
};
