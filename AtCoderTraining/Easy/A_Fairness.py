a, b, c, k = map(int, input().split())

d = (a - b if k % 2 == 0 else b - a)

print(d if d <= int(1e18) else "Unfair")