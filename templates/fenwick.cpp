struct FenwickTree {
    vector<int64_t> bit;  
    int64_t n;

    FenwickTree(int64_t n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int64_t> const &a) : FenwickTree(a.size()) {
        for(int i=0; i < n; i++) {
            bit[i] += a[i];
            int r = i | (i + 1);
            if(r < n) bit[r] += bit[i];
        }
    }

    int64_t sum(int64_t r) {
        int64_t ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int64_t sum(int64_t l, int64_t r) {
        return sum(r) - sum(l - 1);
    }

    void add(int64_t idx, int64_t delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

struct FenwickTreeMin {
    vector<int> bit;
    int n;
    const int INF = (int)1e9;

    FenwickTreeMin(int n) {
        this->n = n;
        bit.assign(n, INF);
    }

    FenwickTreeMin(vector<int> a) : FenwickTreeMin(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int getmin(int r) {
        int ret = INF;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = min(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = min(bit[idx], val);
    }
};
