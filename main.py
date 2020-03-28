st=""
import sortari
import teste
import la
while st!="stop":
    print("generare teste(1),stergere teste(2),sortare(3),nr teste(4)")
    st = input()
    if st=="1":
        print("numar teste:")
        n = int(input())
        print("tip teste(nr mari(1);multe nr(2),sortate(3),identice(4)):")
        st = input()
        if st=="1":
            teste.nrmari(n)
        elif st=="2":
            teste.nrmulte(n)
        elif st=="3":
            teste.nrsortate(n)
        elif st=="4":
            teste.nridentice(n)
        else:
            print("nu exista tipul de teste")
    elif st == "2":
        teste.clear()
    elif st == "3":
        print("tip sortare:\ninsertsort(1);\ncountsort(2);\nradixsort msd(3);\nradicsort lsd(4)\nmergesort(5);\nquicksort(6);\nsortare python(7);")
        st = input()
        if st=="1":
            sortari.timptest(sortari.insertsort)
        elif st=="2":
            sortari.timptest(sortari.countsort)
        elif st=="3":
            sortari.timptest("msd")
        elif st=="4":
            sortari.timptest("lsd")
        elif st=="5":
            sortari.timptest(sortari.mergesort)
        elif st=="6":
            sortari.timptest(sortari.quicksort)
        elif st=="7":
            sortari.timptest("sort")
        elif st=="7":
            la.timptest()
        else:
            print("nu exista sortarea")
    elif st == "4":
        print(sum(1 for line in open('teste.in')))