t = int(input())
mod = int(998244353)
for _ in range(t):
    n = int(input())
    res,used = 1, 0
    for i in range((1 if n % 2 else 2), n+1, 2):
        if i * i == 1:
            used+=1
        else:
            res *= (i * i - used)
            res %= mod
            used+=1
            res *= (i * i -used)
            res %= mod
            used+=1
    print(res)
