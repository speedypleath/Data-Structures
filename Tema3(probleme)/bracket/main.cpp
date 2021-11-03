#include <bits/stdc++.h>

using namespace std;
string cuv;
int max_sequence(int i,int j)
{
    int mx=0,cnt=0;
    char c;
    for(int it=i;it<=j;it++)
    {
        c = cuv[it];
        if(c=='(')
            cnt++;
        else if(cnt>0){
            cnt--;
            mx+=2;
        }
    }
    return mx;
}
int n,m;
int st[20][100000];
int main()
{
    cin>>cuv>>m;
    int c=0,v=0;
    n = cuv.size();
    for(int i=0;i<n;i++)
        cout<<max_sequence(0,i)<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j+(1<<i)<=n;j++)
            st[i][j] = max_sequence(j,j+(1<<i));
    for(int i=0;i<n;i++){
        for(int j=0;j+(1<<i)<=n;j++)
            cout<<st[i][j]<<' ';
        cout<<endl;
    }
    for(int i=0;i<m;i++){
        int a,b,sum=0;
        cin>>a>>b;
        for(int j=20;j>=0;j--) {
            if ((1<<j)<=b-a+1) {
                sum += st[j][a];
                a += 1 << j;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
