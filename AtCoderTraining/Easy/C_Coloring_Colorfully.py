s = input()

n = len(s)

c = '0'
cnt, cnt2 = 0, 0
for i in range(n): 
    if s[i] != c: 
        cnt+=1
    c = ('1' if c == '0' else '0')
    
    
c = '1'
for i in range(n):
    if s[i] != c:
        cnt2 += 1
    c = ('1' if c == '0' else '0')
    
print(min(cnt, cnt2))