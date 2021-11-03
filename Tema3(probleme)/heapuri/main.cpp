#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream in("heapuri.in");
ofstream out("heapuri.out");
int main()
{
    set<int>v;
    int n,i,k=0;
    in>>n;
    int poz[200001];
    for(i=0;i<n;i++)
    {
        int nr,x;
        in>>nr;
        if(nr==1){
            in>>x;
            v.insert(x);
            poz[k++]=x;
        }
        else if(nr==2){
            in>>x;
            v.erase(poz[x-1]);
        }
        else
            out<<*v.begin()<<'\n';
    }
    return 0;
}
