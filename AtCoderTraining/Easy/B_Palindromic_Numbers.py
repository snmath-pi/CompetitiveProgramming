a, b = map(int, input().split())

def chk(s):
    for i in range(len(s)//2):
        if s[i] != s[len(s)-i-1]:
            return False
    return True

cnt = 0
for i in range(a, b+1):
    t = str(i)
    if chk(t):
        cnt+=1

print(cnt)