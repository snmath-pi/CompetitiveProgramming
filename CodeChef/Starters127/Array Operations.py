t = int(input())

def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    
    b = [0]*n
    for i in range(n):
        while a[i] % k == 0:
            a[i] //= k
            b[i] += 1
        
    cnt = sum(b)
    
    l = -1
    r = n + 1
    
    def good(val):
        req = [0]*n
        for i in range(n):
            x = a[i]
            while x < val:
                x *= k
                req[i]+=1
            
        id = list(range(n))
        id.sort(key = lambda x: req[x])
        
        rem, done = cnt, 0
        for i in id:
            if req[i] > rem: break
            if req[i] > b[i]+1: continue
            if req[i] == b[i] + 1 and b[i] > 0: continue
            rem -= req[i]
            done+=1
                
        return True if done >= val else False
        
    while r > l + 1:
        m = l + (r - l) // 2
        
        if good(m):
            l = m
        else:
            r = m
    print(l)
    
for _ in range(t):
    solve()
