n, m = map(int, input().split())
cnt = [0]*(m+1)

for i in range(n):
    k = int(input())
    for j in range(k):
        u = int(input())
        cnt[u]+=1
        
print(sum(1 for x in cnt if x == n))