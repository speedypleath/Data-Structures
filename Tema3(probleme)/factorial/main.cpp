#include <iostream>
#include <fstream>
using namespace std;
ifstream in("fact.in");
ofstream out("fact.out");
int trailingZeroes(int n)
{
    int i = 0;
    while (n>0){
        n /= 5;
        i += n;
    }
    return i;
}
int cautare(int n)
{
    int st=0,dr=5*n+1,m=-1;
    while(st<dr){
        m =(st+dr)/2;
        if(trailingZeroes(m)<n)
            st = m+1;
        else if(trailingZeroes(m)==n)
            return m - m%5;
        else
            dr = m-1;
    }
    return -1;
}
int main()
{
    int p;
    in>>p;
    if(p==0)
        out<<1;
    else
        out<<cautare(p);
}
