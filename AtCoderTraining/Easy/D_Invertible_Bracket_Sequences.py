from collections import Counter
t = int(input())
seg = [0]*(4*2*int(1e5+10))
a = [0]*(2*int(1e5+10))
org = [0]*(2*int(1e5+10))
def build(v, l, r):
    if r == l:
        seg[v] = a[l]
    else:
        m = l + (r-l)//2
        build(v*2, l, m)
        build(v*2+1, m+1, r)
        seg[v] = min(seg[2*v], seg[2*v+1])
def get(v, tl, tr, l, r):
    if l > r:
        return int(1e8)
    if l == tl and r == tr:
        return seg[v]
    tm = tl + (tr-tl)//2
    return min(get(2*v, tl, tm, l, min(tm, r)), get(2*v+1, tm+1,tr,max(tm+1, l), r))
for _ in range(t):
    s = input()
    n = len(s)
    
    for i in range(n):
        a[i] = (a[i-1] if i > 0 else 0)  + (-1 if s[i] == '(' else 1)
        org[i] = (org[i-1] if i > 0 else 0)  + (1 if s[i] == '(' else -1)
    build(1, 0, n-1)
    d = Counter()
    id = Counter()
    sum, ans = 0, 0
    for r in range(n-1, -1, -1):
        sum += (1 if s[r] == '(' else -1)
        i = id[sum]

        if i != 0:
            val = (org[r-1] if r > 0 else 0)
            x = get(1, 0, n-1, r, i-1)
            if 2*val >= -x:
                ans += d[sum]
            else:
                d[sum] = 0
        d[sum]+=1
        id[sum] = r
    print(ans)
    
    
        