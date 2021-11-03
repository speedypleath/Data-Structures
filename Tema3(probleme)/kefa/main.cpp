#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,int>> v;
    int n,d;
    cin>>n>>d;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[i] = make_pair(a,b);
    }
    sort(v.begin(),v.end());
    long long sum[n]={0},mx=0;
    sum[1] = v[0].second;
    for(int i=2;i<=n;i++)
        sum[i] = sum[i-1] + v[i-1].second;
    int st=0,dr=1;
    while(st<n)
    {
        while(v[dr].first - v[st].first<d && dr<n)
            dr++;
        dr--;
        mx = max(sum[dr+1]-sum[st],mx);
        st++;
    }
    cout<<mx;
    return 0;
}
