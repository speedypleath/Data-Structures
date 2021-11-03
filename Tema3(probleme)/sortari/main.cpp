#include <bits/stdc++.h>
#include <fstream>
#include <chrono>
#include <random>
using namespace std::chrono;
using namespace std;
ifstream in("teste.in");
ofstream out("sort.out");
const int N = 10000005;
int v[N], aux[N],n=1000000;
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
void radixSort()
{
    for(int i=0; i<4;i++) {
        if(i%2==0)
            countSort(v, aux, i, n);
        else
            countSort(aux, v, i, n);
    }
}
void interclasare(int st, int m, int dr) {
    int i, j, k;
    i = st;
    j = m;
    k = st;
    while ((i<=m-1)&&(j<=dr)) {
        if (v[i]<=v[j])
            aux[k++]=v[i++];
        else{
            aux[k++] = v[j++];
        }
    }
    while (i<=m-1)
        aux[k++] = v[i++];
    while (j<=dr)
        aux[k++] = v[j++];
    for (i=st;i<=dr;i++)
        v[i] = aux[i];
}
void mergeSort(int st, int dr) {
    int m;
    if (dr>st){
        m = (dr+st)/2;
        mergeSort(st, m);
        mergeSort(m+1, dr);
        interclasare(st, m+1, dr);
    }
}
int partitie (int st, int dr)
{
    swap(v[st+rand()%(dr-st)], v[dr]);
    int pivot = v[dr];
    int i = (st-1);
    for (int j=st;j<=dr-1;j++)
        if (v[j]<pivot)
            swap(v[++i], v[j]);
    swap(v[i+1], v[dr]);
    return i+1;
}
void quickSort(int st, int dr)
{
    if (st<dr){
        int pivot = partitie(st, dr);
        quickSort(st, pivot - 1);
        quickSort(pivot + 1, dr);
    }
}
int main()
{
    int a=0;
    cin>>n;
    for(int i=0;i<n;i++)
        v[i]=rand()%10000000;
    auto t = high_resolution_clock::now();
    quickSort(0,n-1);
    auto stop = high_resolution_clock::now();
    cout<<duration_cast<milliseconds>(stop - t).count();
    cout<<endl<<is_sorted(v,v+n);
    return 0;
}
