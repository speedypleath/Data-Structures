#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream in("radixsort.in");
ofstream out("radixsort.out");
const int N = 10000005;
int v[N], aux[N];
void countSort(int a[],int b[],int index,int n)
{
    int c[256]={0};
    for(int i=0;i<n;i++)
        c[((a[i]>>(8*index))&255)]++;

    for(int i=1;i<256;i++){
        c[i] += c[i-1];
    }
    for(int i=n-1;i>=0;i--){
        b[c[((a[i]>>(8*index))&255)]-1]=a[i];
        c[((a[i]>>(8*index))&255)]--;
    }
}
int main()
{
    long long n,a,b,c;
    in>>n>>a>>b>>c;
    cout<<n<<' '<<a<<' '<<b<<' '<<c;
    v[0] = b;
    for(int i=1;i<n;i++)
        v[i]=(a*v[i-1]+b)%c;
    for(int i=0; i<4;i++) {
        if(i%2==0)
            countSort(v, aux, i, n);
        else
            countSort(aux, v, i, n);
    }
    for(int i=0;i<n;i+=10)
        out<<v[i]<<' ';
    return 0;
}
