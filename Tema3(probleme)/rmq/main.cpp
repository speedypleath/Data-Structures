#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream in("rmq.in");
ofstream out("rmq.out");
int main()
{
    int n,m;
    int mx[100005][20];
    in>>n>>m;
    for(int i=1;i<=n;i++){
        in>>mx[i][0];
    }
	for(int i=1;i<20;i++){
		for (int j=1;j<n-(1<<(i))+1;j++){
			mx[j][i] = min(mx[j][i-1],mx[j+(1<<(i-1))][i-1]);
		}
	}
    for(int i=0;i<m;i++){
        int a,b;
        in>>a>>b;
        int poz=log2(b-a+1);
        out<<min(mx[a][poz],mx[b-(1<<poz)+1][poz])<<'\n;
    }
    return 0;
}
