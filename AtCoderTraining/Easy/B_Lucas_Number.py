n = int(input())

b, a = 2, 1

for i in range(2, n+1):
    c = a + b
    b = a
    a = c

print(a)