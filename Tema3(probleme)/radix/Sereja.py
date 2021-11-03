n,m = (int(x) for x in input().split())
l = [int(x) for x in input().split()]
d = {}
nr = 0
for x in l:
    if x not in d:
        d[x] = 1
        nr += 1
    else:
        d[x] += 1
sol = []
for x in l:
    sol.append(nr)
    d[x] -= 1
    if d[x]==0:
        nr -= 1
for i in range(m):
    k = input()
    k = int(k)
    print(sol[k-1])