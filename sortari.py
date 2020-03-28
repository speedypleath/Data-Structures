
import teste
import random
import time

def insertsort(val):
    if all(x == val[0] for x in val):
        return val
    n = len(val)
    if n == 1:
        return val
    i = 1
    while i < n:
        j = i
        while j > 0 and val[j] < val[j - 1]:
            val[j], val[j - 1] = val[j - 1], val[j]
            j -= 1
        i += 1
    return val


def countsort(val):
    if max(val)>1000000:
        return "numere prea mari!!!"
    f = [0] * (max(val) + 1)
    for x in val:
        f[x] += 1
    j = 0
    for x in range(len(f)):
        for i in range(f[x]):
            val[j] = x
            j += 1
    return val

def radixsort(val, i, k, sol):
    l = [[] for x in range(256)]
    for x in val:
        l[(x & k) >> i].append(x)
    for x in l:
        n = len(x)
        if n in range(1, 50):
            sol += insertsort(x)
        elif n >= 50:
            radixsort(x, i - 8, k >> 8, sol)
    return sol


def index(x):
    i = 8
    while x >> i != 0:
        i += 8
    k = (1 << i) - 1
    i -= 8
    return i, k


def interclasare(a, b):
    i = 0
    j = 0
    l = []
    while i != len(a) and j != len(b):
        if a[i] < b[j]:
            l.append(a[i])
            i += 1
        else:
            l.append(b[j])
            j += 1
    l += a[i:]
    l += b[j:]
    return l


def mergesort(l):
    if len(l) in range(15):
        return insertsort(l)
    else:
        return interclasare(mergesort(l[:len(l) // 2]), mergesort(l[len(l) // 2:]))


def mediana(l):
    if len(l) <= 5:
        return sorted(l)[len(l) // 2]
    sub = [l[i:i + 6] for i in range(0, len(l), 5)]
    mediane = [sorted(x)[len(x) // 2] for x in sub]
    return mediana(mediane)


def quicksort(l):
    if len(l) > 15:
        pivot = random.choice(l)
        s = [x for x in l if x < pivot]
        e = [x for x in l if x == pivot]
        d = [x for x in l if x > pivot]
        return quicksort(s) + e + quicksort(d)
    else:
        return insertsort(l)
def radixlsd(l,max,i):
    new = [[] for x in range(256)]
    for aux in l:
        for x in aux:
            new[(x & 255 << i) >> i].append(x)
    if (max & 255 << i) >> i == 0:
        return new[0]
    else:
        return radixlsd(new,max,i+8)

def par(l):
    new = [[] for x in range(256)]
    for x in l:
        new[x & 255].append(x)
    return new,max(l)
def timptest(sortare):
    g = open("teste.in")
    val = teste.untest(g)
    start = time.time()
    while val != []:
        sol = []
        if sortare=="msd":
            val=radixsort(val,*index(max(val)),sol)
        elif sortare=="lsd":
            val=radixlsd(*par(val),8)
        elif sortare=="sort":
            val.sort()
        else:
            val = sortare(val)
        val = teste.untest(g)
        if time.time() - start>5:
            print("timpul de sortare e prea lung!!")
            break
    print(time.time() - start)

