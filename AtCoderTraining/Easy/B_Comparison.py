s = input()
t = input()

if len(s) > len(t):
    print("GREATER")
elif len(s) < len(t):
    print("LESS")
else:
    ok = False
    for i in range(len(s)):
        if s[i] > t[i]:
            print("GREATER")
            exit(0)
        elif s[i] < t[i]:
            print("LESS")
            exit(0)
    print("EQUAL")