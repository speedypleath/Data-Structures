import random
import time
f = open("abce.in")
g = open("abce.out","w")
class Nod:
    def __init__(self):
        self.val = []
        self.child = [None]
        self.lungime = 0
        self.parent = None

    def __add__(self, other):
        i = self.index(other)
        self.val = self.val[:i] + [other] + self.val[i:]
        self.child = self.child[:i] + [None] + self.child[i:]
        self.lungime += 1

    def index(self, val):
        i = 0
        while i < self.lungime and val > self.val[i]:
            i += 1
        return i

    def parent_child(self):
        for x in self.child:
            if x is not None:
                x.parent = self

    def split(self, aux, indice):
        k = aux.lungime // 2
        self.child[indice] = Nod()
        self.child[indice + 1] = Nod()
        for x in aux.val[:k]:  # copiere valori
            self.child[indice] + x
        for x in aux.val[k + 1:]:
            self.child[indice + 1] + x
        self.child[indice].child = aux.child[:k + 1]  # copiere copii
        self.child[indice + 1].child = aux.child[k + 1:]
        self.parent_child()
        self.child[indice].parent_child()
        self.child[indice + 1].parent_child()
    def union(self,nod,i):
        self.child = self.child + nod.child
        self.val = self.val + [self.parent.val[i]] + nod.val
        self.lungime = len(self.val)
        self.parent.child.remove(nod)
        self.parent.val.remove(self.parent.val[i])
        self.parent.lungime -= 1
class BTree:
    grad = 11
    def __init__(self):
        self.root = Nod()

    def insert(self, val):
        cur, i = self.traverse(val)
        cur + val
        while cur.lungime >= self.grad:
            if cur.parent is None:
                cur.parent = Nod()
                self.root = cur.parent
            nou = cur.parent
            mediana = cur.val[cur.lungime // 2]
            indice = nou.index(val)
            nou + mediana
            nou.split(cur, indice)
            cur = nou

    def traverse(self, val):
        cur = self.root
        i = cur.index(val)
        while self.grad > cur.lungime and cur.child[i] is not None:
            cur = cur.child[i]
            i = cur.index(val)
        return cur, i

    def afisare(self, cur, nivel=0):
        if cur.parent is not None:
            print(cur.val, nivel,"lungime",len(cur.parent.val))
        else:
            print(cur.val, nivel)
        for i in cur.child:
            if i is not None:
                self.afisare(i, nivel + 1)

    def sortat(self,cur,st,dr):
        ok = 1
        for i in cur.child:
            if i is not None:
                ok = 0
                self.sortat(i,st,dr)
                aux = cur.child.index(i)
                if aux < cur.lungime:
                    if cur.val[aux]>dr:
                        return
                    if cur.val[aux]>=st:
                        g.write(str(cur.val[aux]))
                        g.write(' ')
        if ok:
            for x in cur.val:
                if x > dr:
                    return
                if x >= st:
                    g.write(str(x))
                    g.write(' ')
    def find(self,cur,val):
        if cur is None:
            return None,0
        cur.parent_child()
        i = cur.index(val)
        if i == cur.lungime or cur.val[i]>val:
            return self.find(cur.child[i],val)
        elif cur.val[i]==val:
            return cur,i
        else:
            return self.find(cur.child[i+1],val)
    def delete(self,val):
        cur, i = self.find(self.root,val)
        if cur is None:
            return 0
        if all(cur.child):
            x = self.succ(val)
            aux,j = self.find(self.root,x)
            if aux.lungime>self.grad//2:
                cur.val[i],aux.val[j] = aux.val[j],cur.val[i]
                cur = aux
            else:
                x = self.pred(val)
                aux, j = self.find(self.root, x)
                cur.val[i], aux.val[j] = aux.val[j], cur.val[i]
                cur = aux
            i = j
        cur.val = cur.val[:i] + cur.val[i + 1:]
        cur.lungime -= 1
        cur.child = cur.child[:i] + cur.child[i + 1:]
        if cur.lungime<self.grad//2 and cur.parent is not None:
            return self.balance(cur)
    def balance(self,cur):
        if cur.parent is not None:
            if cur not in cur.parent.child:
                self.afisare(self.root)
                return 1
            k = cur.parent.child.index(cur)
            if cur.lungime < self.grad // 2:
                if k > 0 and cur.parent.child[k - 1].lungime > self.grad // 2:
                    cur.val.insert(0, cur.parent.val[k - 1])
                    cur.parent.val[k - 1] = cur.parent.child[k - 1].val[-1]
                    cur.child.insert(0, cur.parent.child[k - 1].child[-1])
                    cur.lungime += 1
                    del cur.parent.child[k - 1].val[-1]
                    del cur.parent.child[k - 1].child[-1]
                    cur.parent.child[k - 1].lungime -= 1
                elif k < cur.parent.lungime and cur.parent.child[k + 1].lungime > self.grad // 2:
                    cur.val.append(cur.parent.val[k])
                    cur.lungime += 1
                    cur.parent.val[k] = cur.parent.child[k + 1].val[0]
                    del cur.parent.child[k + 1].val[0]
                    cur.child.append(cur.parent.child[k + 1].child[0])
                    del cur.parent.child[k + 1].child[0]
                    cur.parent.child[k + 1].lungime -= 1
                else:
                    if k == cur.parent.lungime:
                        cur.parent.child[k - 1].union(cur, k - 1)
                    else:
                        cur.union(cur.parent.child[k + 1], k)
                    if cur.parent is not None and cur.parent.lungime < self.grad // 2:
                        self.balance(cur.parent)
                    if cur.parent is None:
                        self.root = cur
        else:
            if cur.val == []:
                cur.child[0].parent = None
                self.root = cur.child[0]
    def succ(self,val):
        cur, i = self.find(self.root,val)
        if not all(cur.child):
            return 0
        if cur.child[i+1] is not None:
            cur = cur.child[i + 1]
            while cur.child[0] is not None:
                cur = cur.child[0]
            return cur.val[0]
        else:
            k = cur.parent.child.index(cur)
            if val != cur.val[-1]:
                return cur.val[cur.index(val) + 1]
            elif k<cur.parent.lungime:
                return cur.parent.val[i]
            else:
                j = self.root.index(val)
                if j<self.root.lungime:
                    return self.root.val[j]
                else:
                    return "nu exista"
    def pred(self,val):
        cur, i = self.find(self.root,val)
        if not all(cur.child):
            return 0
        if cur.child[i] is not None:
            cur = cur.child[i]
            while cur.child[-1] is not None:
                cur = cur.child[-1]
            return cur.val[-1]
        else:
            k = cur.parent.child.index(cur)
            if val != cur.val[0]:
                return cur.val[cur.index(val)-1]
            elif k>0:
                return cur.parent.val[i]
            else:
                j = self.root.index(val)
                if j>0:
                    return self.root.val[j-1]
                else:
                    return "nu exista"
    def succesor(self,val):
        cur = self.root
        while all(cur.child):
            cur = cur.child[cur.index(val)]
        while cur.index(val) == cur.lungime:
            cur = cur.parent
            if cur is None:
                break
        else:
            return cur.val[cur.index(val)]
        return -1
    def predecesor(self,val):
        cur = self.root
        if val in cur.val:
            return val
        while all(cur.child):
            cur = cur.child[cur.index(val)]
            if val in cur.val:
                return val
        while cur.index(val) == 0:
            cur = cur.parent
            if cur is None:
                break
        else:
            return cur.val[cur.index(val)-1]
        return -1
ob = BTree()
n = int(f.readline())
for i in range(n):
    st = f.readline()
    if st[0] == '6':
        (a,b,c) = (int(x) for x in st.split())
        ob.sortat(ob.root,b,c)
        g.write('\n')
    else:
        (a,b) = (int(x) for x in st.split())
        if a == 1:
            ob.insert(b)
        elif a == 2:
            ob.delete(b)
        elif a == 3:
            cur,i = ob.find(ob.root,b)
            if cur is None:
                g.write('0\n')
            else:
                g.write('1\n')
        elif a == 4:
            g.write(str(ob.predecesor(b)))
            g.write('\n')
        elif a == 5:
            g.write(str(ob.succesor(b)))
            g.write('\n')
f.close()
g.close()
exit(0)