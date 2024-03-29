t = int(input())

for _ in range(t):
    a, b = map(int, input().split())

    if a - b >= 10:
        print(0)
    else:
        print((b + 10 - a) // 3 if (b + 10 - a) % 3 == 0 else (b + 10 - a + 3) // 3)
