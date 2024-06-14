n = int(input())

s = set()
prev = ""
for i in range(n):
    t = input()
    if t in s:
        print("No")
        exit(0)
    if i:
        if t[0] != prev[-1]:
            print("No")
            exit(0)
    prev = t
    s.add(t)
print("Yes")