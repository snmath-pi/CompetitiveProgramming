n, m = map(int, input().split())

a = [0]*(n+1)

for i in range(m):
    u, v = map(int, input().split())
    a[u]+=1
    a[v] +=1
    
for i in range(1, n+1):
    print(a[i])