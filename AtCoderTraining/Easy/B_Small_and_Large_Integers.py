a, b, k = map(int, input().split())

s = set()

for i in range(a, b+1):
    if i<a+k or i>b-k:
        s.add(i)

 
for i in sorted(s):
    print(i)