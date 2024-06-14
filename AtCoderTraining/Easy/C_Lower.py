n = int(input())

a = list(map(int, input().split()))

ans = 0

for i in range(n):
    cnt = 0
    while i + 1 < n and a[i+1] <= a[i]:
        i+=1
        cnt += 1
    ans = max(ans, cnt)
    
print(ans)