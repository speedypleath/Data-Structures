#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream in("pikachu.in");
ofstream out("pikachu.out");
long long n,k,v[100005];
long long rez(long long x)
{
    long long sol = 0, val = 0;
    for (int i=0;i<k;i++)
        val += (long long) abs(x-v[i]);
    sol = val;
    for (int i=k;i<n;i++) {
        val -= (long long)abs(x-v[i-k]);
        val += (long long)abs(x-v[i]);
        sol = min(sol, val);
    }
    return sol;
}
int main()
{
    in>>n>>k;
    for(int i=0;i<n;i++)
        in>>v[i];
    long long st=1,dr=2e9;
    while(st<=dr){
        long long m = (st+dr)/2;
        if(rez(m-1)>rez(m+1))
            st = m+1;
        else
            dr = m-1;
    }
    out<<rez(st);
    return 0;
}
