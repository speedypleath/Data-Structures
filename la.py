inf = float("9e999")
f= open("teste.in")
import sortari
import teste
import time
class Turnament:
    def __init__(self,k):
        self.l=[]
        self.nivel=k
        for i in range(0,self.nivel+1):
            aux=[None]*(2**i)
            self.l.append(aux)
    def __add__(self,val):
        if None in self.l[self.nivel]:
            x = self.l[self.nivel].index(None)
            self.l[self.nivel][x]=val
            self.play(self.nivel,x)
        else:
            print("arbore plin")
    def play(self,a,b):
        if a==0 or a>self.nivel or self.l[a][b]==None:
            return
        if self.l[a-1][b//2]==None:
            if b%2==0 and self.l[a][b+1]!=None:
                aux=min(self.l[a][b],self.l[a][b+1])
            elif b%2==1 and self.l[a][b-1]!=None:
                aux = min(self.l[a][b], self.l[a][b - 1])
            else:
                return
            if a>=0:
                self.l[a - 1][b // 2] = aux
                k = self.l[a].index(aux)
                self.l[a][k] = None
                if a<self.nivel and (self.l[a+1][k*2]!=None and self.l[a+1][k*2+1]!=None):
                    self.play(a+1,k*2)
                self.play(a - 1, b//2)
        else:
            if self.l[a][b]<self.l[a-1][b//2]:
                (self.l[a][b],self.l[a - 1][b // 2])=(self.l[a-1][b//2],self.l[a][b])
                self.play(a - 1, b // 2)
    def pop(self):
        aux=self.l[0][0]
        self.l[0][0]=None
        self.play(1,0)
        return aux
b = Turnament(10)
l = [12, 10, 9, 20, 8, 4, 1, 6, 19, 18, 15, 11, 19, 2, 7, 5, 16, 9, 14, 17]
nou = []
sol=[]
def toursort(l):
    b = Turnament(5)
    nou = []
    sol = []
    for x in l:
        b+x
        if b.l[0][0]!=None:
            aux = b.pop()
            if sol==[] or aux>sol[-1]:
                sol.append(aux)
            else:
                nou.append(aux)
    while b.l[0][0] != None:
        b.pop()
    aux=0
    while aux != inf:
        for i in range(len(b.l[b.nivel])):
            if b.l[b.nivel][i] == None:
                b.l[b.nivel][i] = inf
                b.play(b.nivel, i)
        aux = b.pop()
        if aux!=inf:
            if sol == [] or aux > sol[-1]:
                sol.append(aux)
            else:
                nou.append(aux)
    if nou!=[]:
        if len(nou)<20:
            nou=sortari.insertsort(nou)
        else:
            nou=toursort(nou)
        sol=sortari.interclasare(sol,nou)
    return sol

def timptest():
    g = open("teste.in")
    val = teste.untest(g)
    start = time.time()
    while val != []:
        sol = []
        sol=toursort(val)
        print(teste.verificare(sol))
        val = teste.untest(g)
        #if time.time() - start>5:
         #   print("timpul de sortare e prea lung!!")
          #  break
    print(time.time() - start)