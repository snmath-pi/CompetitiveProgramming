import bisect
t = int(input())

for _ in range(t):
    n = int(input())
    
    s = input()
    t = input()
    
    ok = True
    pos = []
    a = []
    c = []
    
    for i in range(n):
        if s[i] == 'b' and t[i] != 'b' or s[i] == 'a' and t[i] == 'b' or s[i] == 'c' and t[i] == 'b':
            ok = False
        if s[i] == t[i] and s[i] == 'b':
            pos.append(i)
        if s[i] == 'a' and t[i] == 'c':
            a.append(i)
        if s[i] == 'c' and t[i] == 'a':
            c.append(i)
    
    if not ok:
        print('No')
        continue
    
    if len(a) != len(c):
        print('No')
        continue
    
    
    for j in range(len(a)):
        if a[j] > c[j]:
            ok = False
            break
        val = bisect.bisect_left(pos, a[j])
    
        if val == len(pos):
            ok = False
            break
        
        val = pos[val]
        if val > c[j]:
            ok = False
            break
    
    print('Yes' if ok else 'No')
            
    
    
    
