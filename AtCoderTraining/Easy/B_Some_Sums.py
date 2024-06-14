n, a, b = map(int, input().split())

ans = 0

for i in range(1, n + 1):
    val = sum(int(d) for d in str(i))
    if val>=a and val <= b:
        ans += i
print(ans)