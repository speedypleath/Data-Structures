#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream in("mexitate.in");
ofstream out("mexitate.out");
vector<int> a[400005];
int fr[400005],frsqrt[640];
int n,m,k,l;
int first()
{
    for(int i=0;i<640;i++)
    if(frsqrt[i]<640)
        for(int j=i*640;j<(i+1)*640;j++)
            if(fr[j]==0)
                return j;
    return 1;
}
int rez(int n1)
{
    memset(fr,0,sizeof(fr));
    memset(frsqrt,0,sizeof(frsqrt));
    fr[0]=1;
    frsqrt[0]=1;
    for(int i=n1;i<n1+k;i++)
        for(int j=0;j<l;j++){
            fr[a[i][j]]++;
            if(fr[a[i][j]]==1)
                frsqrt[a[i][j]/640]++;
        }
    long long sol = first();
    for(int j=l;j<m;j++){
        for(int i=n1;i<n1+k;i++){
            fr[a[i][j]]++;
            if(fr[a[i][j]]==1)
                frsqrt[a[i][j]/640]++;
        }
        for(int i=n1;i<n1+k;i++){
            fr[a[i][j-l]]--;
            if(fr[a[i][j-l]]==0)
                frsqrt[a[i][j-l]/640]--;
        }
        sol = (1LL*sol*first())%1000000007;
    }
    return sol;
}
int main()
{
    in>>n>>m>>k>>l;
    if(n>m){
        swap(n,m);
        swap(l,k);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                int val;
                in>>val;
                a[j].push_back(val);
            }
    }
    else{
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                int val;
                in>>val;
                a[i].push_back(val);
            }
    }
    long long prod = 1;
    for(int i=0;i<=n-k;i++){
            prod = (1LL*prod*rez(i))%1000000007;
    }
    out<<prod;
    return 0;
}
