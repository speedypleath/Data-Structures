#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream in("vila2.in");
ofstream out("vila2.out");
int n,k;
queue<int> q;
int main()
{
    int mx=0,mn=300007;
    in>>n>>k;
    for(int i=0;i<k;i++)
    {
        int aux;
        in>>aux;
        mn = min(mn,aux);
        mx = max(mx,aux);
        q.push(aux)
    }
    return 0;
}
