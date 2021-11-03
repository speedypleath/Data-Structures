l = [0]*10
st = 0
dr = 9
n = input()
s = input()
for x in s:
    if x == 'L':
        st = l.index(0)
        l[st] = 1
    elif x == 'R':
        dr = 9 - l[::-1].index(0)
        l[dr] = 1
    else:
        l[int(x)] = 0
print(*l,sep="")