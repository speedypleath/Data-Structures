#include <bits/stdc++.h>

using namespace std;
ifstream in("farfurii.in");
ofstream out("farfurii.out");
int main()
{
    long long k,n,i=1;
    in>>n>>k;
    while((n-i)*(n-i-1)/2>k){
        out<<i<<' ';
        i++;
    }
    long long aux = k-(n-i)*(n-i-1)/2+i;
    out<<aux<<' ';
    for(int j=n;j>aux;j--)
        out<<j<<' ';
    for(int j=aux-1;j>=i;j--)
        out<<j<<' ';
    return 0;
}
