t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    val = 1 + max(0, (k+1)*(k+2)//2-3)
    print("YES" if n >= val else "NO")