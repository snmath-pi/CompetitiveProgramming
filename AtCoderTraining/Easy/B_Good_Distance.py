import math
n, d = map(int, input().split())

l = []
for i in range(n):
    a = list(map(int, input().split()))
    l.append(a)

cnt = 0
def good(n):
    t = math.sqrt(n)
    return t.is_integer()
for i in range(n):
    for j in range(i+1, n):
        tot = 0
        for k in range(d):
            tot += (l[i][k]-l[j][k])**2
        if good(tot):
            cnt+=1
print(cnt)        