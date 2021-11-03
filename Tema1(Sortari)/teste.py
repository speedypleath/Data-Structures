import random
f = open("teste.in", "w")
def clear():
    f.seek(0)
    f.truncate()
def nrmulte(n):
    for i in range(n):
        st = ""
        for j in range(random.randrange(1000,3000)):
            x = str(random.randrange(10000))
            st += x + ' '
        f.write(st)
        f.write('\n')
def nrmari(n):
    for i in range(n):
        st=""
        for j in range(random.randrange(100,600)):
            x=str(random.randrange(20000000,200000000))
            st+=x+' '
        f.write(st+'\n')

def nridentice(n):
    x = str(random.randrange(10000))
    for i in range(n):
        st = ""
        for j in range(random.randrange(500,3000)):
            st += x + ' '
        f.write(st)
        f.write('\n')
def nrsortate(n):
    for i in range(n):
        st = ""
        for j in range(random.randrange(500,3000)):
            st += str(j) + ' '
        f.write(st)
        f.write('\n')
def verificare(val):
    if(all(val[i] <= val[i + 1] for i in range(len(val)-1))):
        return "da"
    else:
        return "nu"
def untest(f):
    l=[int(x) for x in f.readline().split() if x[0].isdigit]
    return l