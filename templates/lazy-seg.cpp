/* add to segment (l, r) find value at a given point i */
/* to get the answer obviously return seg.get() + a[i] since 
    this tree starts with op[v] = 0*/

struct segTree {
    vector<long long> tr, op;
    int size;
    const long long neutral_element = 0; 
    segTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tr.resize(size * 2);
        op.resize(size * 2);
        
    }
    long long addSeg(long long x, long long y) {
        return x + y;
    }
    long long minSeg(long long x, long long y) {
        return (x < y ? x : y);
    }
    long long maxSeg(long long x, long long y) {
        return (x > y ? x : y);
    }
    long long xorSeg(long long x, long long y) {
        return x ^ y;
    }
    long long orSeg(long long x, long long y) {
        return x | y;
    }

    void build(int v, int lx, int rx, vector<long long> &a) {
        if(rx - lx == 1) {
            if(lx < (int) a.size()) {
                op[v] = a[lx];
            }
            return;
        }
        int mx = (lx + rx) / 2;
        build(2 * v + 1, lx, mx, a);
        build(2 * v + 2, mx, rx, a);
    }
    void build(vector<long long> &a) {
        build(0, 0, size, a);
    }

    void add(int v, int lx, int rx, int l, int r, int val) {
        if(rx <= l || lx >= r) {
            return;
        }
        if(rx <= r && lx >= l) {
            op[v] += val;
            return;
        }
        int mx = (lx + rx) / 2;
        add(2 * v + 1, lx, mx, l, r, val);
        add(2 * v + 2, mx, rx, l, r, val);
        
    }
    void add(int l, int r, int val) {
        add(0, 0, size, l, r, val);
    }

    long long get(int v, int lx, int rx, int id) {
        if(rx - lx == 1) {
            return op[v];
        }
        long long cur = 0;
        int mx = (lx + rx) / 2;
        if(id < mx) {
            cur = get(2 * v + 1, lx, mx, id);
        } else {
            cur = get(2 * v + 2, mx, rx, id);
        }
        return cur + op[v];
    }   
    long long get(int id) {
        return get(0, 0, size, id);
    }

};



/* addition to a segment (l, r-1) and find the minimum in some segment (l, r-1)*/

struct segTree {
    vector<long long> tr, op;
    int size;
    const long long NULL_VALUE = LLONG_MAX; 
    segTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tr.assign(size * 2, 0LL);
        op.assign(size * 2, 0LL);
        
    }
    long long addSeg(long long x, long long y) {
        return x + y;
    }
    long long minSeg(long long x, long long y) {
        return (x < y ? x : y);
    }
    long long maxSeg(long long x, long long y) {
        return (x > y ? x : y);
    }
    long long xorSeg(long long x, long long y) {
        return x ^ y;
    }
    long long orSeg(long long x, long long y) {
        return x | y;
    }

    void build(int v, int lx, int rx, vector<long long> &a) {
        if(rx - lx == 1) {
            if(lx < (int) a.size()) {
                tr[v] = a[lx];
            }
            return;
        }
        int mx = (lx + rx) / 2;
        build(2 * v + 1, lx, mx, a);
        build(2 * v + 2, mx, rx, a);
        tr[v] = minSeg(tr[2 * v + 1], tr[2 * v + 2]);
    }
    void build(vector<long long> &a) {
        build(0, 0, size, a);
    }

    void add(int v, int lx, int rx, int l, int r, int val) {
        if(rx <= l || lx >= r) {
            return;
        }
        if(rx <= r && lx >= l) {
            op[v] += val;
            tr[v] += val;
            return;
        }
        int mx = (lx + rx) / 2;
        add(2 * v + 1, lx, mx, l, r, val);
        add(2 * v + 2, mx, rx, l, r, val);
        tr[v] = op[v] + minSeg(tr[2 * v + 1], tr[2 * v + 2]);

    }
    void add(int l, int r, int val) {
        add(0, 0, size, l, r, val);
    }

    long long get(int v, int lx, int rx, int l, int r) {
        if(rx <= l || lx >= r) {
            return NULL_VALUE;
        }
        if(rx <= r && lx >= l) {
            return tr[v];
        }
        int mx = (lx + rx) / 2;
        long long a1 = get(2 * v + 1, lx, mx, l, r);
        long long a2 = get(2 * v + 2, mx, rx, l, r);
        return op[v]+minSeg(a1, a2);
    }   
    long long get(int l, int r) {
        return get(0, 0, size, l, r);
    }

};

/* mult a segment and find sum of segment*/

struct segTree {
    vector<long long> tr, op;
    int size;
    const long long NULL_VALUE = 0; 
    segTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tr.assign(size * 2, 0LL);
        op.assign(size * 2, 1LL);
        
    }
    long long addSeg(long long x, long long y) {
        return x + y;
    }
    long long minSeg(long long x, long long y) {
        return (x < y ? x : y);
    }
    long long maxSeg(long long x, long long y) {
        return (x > y ? x : y);
    }
    long long xorSeg(long long x, long long y) {
        return x ^ y;
    }
    long long orSeg(long long x, long long y) {
        return x | y;
    }

    void build(int v, int lx, int rx, vector<long long> &a) {
        if(rx - lx == 1) {
            if(lx < (int) a.size()) {
                tr[v] = a[lx];
            }
            return;
        }
        int mx = (lx + rx) / 2;
        build(2 * v + 1, lx, mx, a);
        build(2 * v + 2, mx, rx, a);
        tr[v] = add(tr[2 * v + 1], tr[2 * v + 2]);
    }
    void build(vector<long long> &a) {
        build(0, 0, size, a);
    }

    void modify(int v, int lx, int rx, int l, int r, int val) {
        if(rx <= l || lx >= r) {
            return;
        }
        if(rx <= r && lx >= l) {
            op[v] = mult(op[v], val);
            tr[v] = mult(tr[v], val);
            return;
        }
        int mx = (lx + rx) / 2;
        modify(2 * v + 1, lx, mx, l, r, val);
        modify(2 * v + 2, mx, rx, l, r, val);
        tr[v] = mult(op[v], add(tr[2 * v + 1], tr[2 * v + 2]));

    }
    void modify(int l, int r, int val) {
        modify(0, 0, size, l, r, val);
    }

    long long calc(int v, int lx, int rx, int l, int r) {
        if(rx <= l || lx >= r) {
            return NULL_VALUE;
        }
        if(rx <= r && lx >= l) {
            return tr[v];
        }
        int mx = (lx + rx) / 2;
        long long a1 = calc(2 * v + 1, lx, mx, l, r);
        long long a2 = calc(2 * v + 2, mx, rx, l, r);
        return mult(op[v], add(a1, a2));
    }   
    long long calc(int l, int r) {
        return calc(0, 0, size, l, r);
    }

};

/* add to a segment a value, find the sum of all the elements in given query */

struct segTree {
    vector<long long> tr, op;
    int size;
    const long long NULL_VALUE = 0; 
    segTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tr.assign(size * 2, 0LL);
        op.assign(size * 2, 0LL);
        
    }
    long long addSeg(long long x, long long y) {
        return x + y;
    }
    long long minSeg(long long x, long long y) {
        return (x < y ? x : y);
    }
    long long maxSeg(long long x, long long y) {
        return (x > y ? x : y);
    }
    long long xorSeg(long long x, long long y) {
        return x ^ y;
    }
    long long orSeg(long long x, long long y) {
        return x | y;
    }
    long long andSeg(long long x, long long y) {
        return x & y;
    }

    void build(int v, int lx, int rx, vector<long long> &a) {
        if(rx - lx == 1) {
            if(lx < (int) a.size()) {
                tr[v] = a[lx];
            }
            return;
        }
        int mx = (lx + rx) / 2;
        build(2 * v + 1, lx, mx, a);
        build(2 * v + 2, mx, rx, a);
        tr[v] = add(tr[2 * v + 1], tr[2 * v + 2]);
    }
    void build(vector<long long> &a) {
        build(0, 0, size, a);
    }

    void modify(int v, int lx, int rx, int l, int r, int val) {
        if(rx <= l || lx >= r) {
            return;
        }
        if(rx <= r && lx >= l) {
            op[v] = addSeg(op[v], val);
            tr[v] = addSeg(tr[v], (rx-lx)*1ll*val);
            return;
        }
        int mx = (lx + rx) / 2;
        modify(2 * v + 1, lx, mx, l, r, val);
        modify(2 * v + 2, mx, rx, l, r, val);
        tr[v] = addSeg(op[v]*(rx-lx), addSeg(tr[2 * v + 1], tr[2 * v + 2]));

    }
    void modify(int l, int r, int val) {
        modify(0, 0, size, l, r, val);
    }

    long long calc(int v, int lx, int rx, int l, int r) {
        if(rx <= l || lx >= r) {
            return NULL_VALUE;
        }
        if(rx <= r && lx >= l) {
            return tr[v];
        }
        int mx = (lx + rx) / 2;
        long long a1 = calc(2 * v + 1, lx, mx, l, r);
        long long a2 = calc(2 * v + 2, mx, rx, l, r);
        return addSeg(addSeg(a1, a2), op[v] * 1ll * (min(rx, r) - max(lx, l)));
    }   
    long long calc(int l, int r) {
        return calc(0, 0, size, l, r);
    }

};

/* in a segment (l, r) ASSIGN the value val, then find the min of query */

struct segTree {
    vector<long long> tr, op;
    int size;
    const long long NO_OPERATION = LLONG_MAX;  
    const long long NULL_VALUE = LLONG_MAX;   

    segTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tr.assign(size * 2, 0);
        op.assign(size * 2, NO_OPERATION);
    }

    long long calc_op(long long a, long long b) {
        return min(a, b);
    }

    long long modify_op(long long a, long long b, long long len) {
        return (b == NO_OPERATION) ? a : b;
    }

    void apply_op(long long &a, long long b, long long len) {
        a = modify_op(a, b, len);
    }

    void propagate(int v, int lx, int rx) {
        if (op[v] == NO_OPERATION || rx - lx == 1) return;
        int m = (lx + rx) / 2;
        apply_op(tr[2 * v + 1], op[v], m - lx);
        apply_op(op[2 * v + 1], op[v], 1);
        apply_op(tr[2 * v + 2], op[v], rx - m);
        apply_op(op[2 * v + 2], op[v], 1);
        op[v] = NO_OPERATION;
    }

    void build(int v, int lx, int rx, const vector<long long> &a) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                tr[v] = a[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(2 * v + 1, lx, m, a);
        build(2 * v + 2, m, rx, a);
        tr[v] = calc_op(tr[2 * v + 1], tr[2 * v + 2]);
    }

    void build(const vector<long long> &a) {
        build(0, 0, size, a);
    }

    void modify(int v, int lx, int rx, int l, int r, long long val) {
        propagate(v, lx, rx);
        if (rx <= l || lx >= r) return;
        if (lx >= l && rx <= r) {
            apply_op(tr[v], val, rx - lx);
            apply_op(op[v], val, 1);
            return;
        }
        int m = (lx + rx) / 2;
        modify(2 * v + 1, lx, m, l, r, val);
        modify(2 * v + 2, m, rx, l, r, val);
        tr[v] = calc_op(tr[2 * v + 1], tr[2 * v + 2]);
    }

    void modify(int l, int r, long long val) {
        modify(0, 0, size, l, r, val);
    }

    long long calc(int v, int lx, int rx, int l, int r) {
        propagate(v, lx, rx);
        if (rx <= l || lx >= r) return NULL_VALUE;
        if (lx >= l && rx <= r) return tr[v];
        int m = (lx + rx) / 2;
        long long s1 = calc(2 * v + 1, lx, m, l, r);
        long long s2 = calc(2 * v + 2, m, rx, l, r);
        return calc_op(s1, s2);
    }

    long long calc(int l, int r) {
        return calc(0, 0, size, l, r);
    }
};


/*assign the value to the segment and find the sum */


struct segTree {
    vector<long long> tr, op;
    int size;
    const long long NO_OPERATION = LLONG_MAX;  
    const long long NULL_VALUE = 0;   

    segTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tr.assign(size * 2, 0);
        op.assign(size * 2, 0);
    }

    long long calc_op(long long a, long long b) {
        return a+b;
    }

    long long modify_op(long long a, long long b, long long len) {
        return (b == NO_OPERATION) ? a : b * len;
    }

    void apply_op(long long &a, long long b, long long len) {
        a = modify_op(a, b, len);
    }

    void propagate(int v, int lx, int rx) {
        if (op[v] == NO_OPERATION || rx - lx == 1) return;
        int m = (lx + rx) / 2;
        apply_op(tr[2 * v + 1], op[v], m - lx);
        apply_op(op[2 * v + 1], op[v], 1);
        apply_op(tr[2 * v + 2], op[v], rx - m);
        apply_op(op[2 * v + 2], op[v], 1);
        op[v] = NO_OPERATION;
    }

    void build(int v, int lx, int rx, const vector<long long> &a) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                tr[v] = a[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(2 * v + 1, lx, m, a);
        build(2 * v + 2, m, rx, a);
        tr[v] = calc_op(tr[2 * v + 1], tr[2 * v + 2]);
    }

    void build(const vector<long long> &a) {
        build(0, 0, size, a);
    }

    void modify(int v, int lx, int rx, int l, int r, long long val) {
        propagate(v, lx, rx);
        if (rx <= l || lx >= r) return;
        if (lx >= l && rx <= r) {
            apply_op(tr[v], val, rx - lx);
            apply_op(op[v], val, 1);
            return;
        }
        int m = (lx + rx) / 2;
        modify(2 * v + 1, lx, m, l, r, val);
        modify(2 * v + 2, m, rx, l, r, val);
        tr[v] = calc_op(tr[2 * v + 1], tr[2 * v + 2]);
    }

    void modify(int l, int r, long long val) {
        modify(0, 0, size, l, r, val);
    }

    long long calc(int v, int lx, int rx, int l, int r) {
        propagate(v, lx, rx);
        if (rx <= l || lx >= r) return NULL_VALUE;
        if (lx >= l && rx <= r) return tr[v];
        int m = (lx + rx) / 2;
        long long s1 = calc(2 * v + 1, lx, m, l, r);
        long long s2 = calc(2 * v + 2, m, rx, l, r);
        return calc_op(s1, s2);
    }

    long long calc(int l, int r) {
        return calc(0, 0, size, l, r);
    }
};
