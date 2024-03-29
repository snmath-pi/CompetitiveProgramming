t = int(input())

for _ in range(t):
    
    n, l = map(int, input().split())
    
    rng = 999 + 1000
    
    ret = []
    if l >= rng:
        for _ in range(n):
            ret.append(_+1)
    else:
        for _ in range(n):
            ret.append(1 + _ * l)
     
    print(' '.join(map(str, ret)))  
