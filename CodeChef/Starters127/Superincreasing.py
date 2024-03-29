t = int(input())

for _ in range(t):
    n, k, x = map(int, input().split())
    
    for _ in range(k-1):
        x = x // 2
    
    print('Yes' if x > 0 else 'No')
